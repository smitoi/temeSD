def largest_concat_number(numbers):
    rez = "";

    for i in range(len(numbers)):
        for j in range(n + 1, len(numbers)):
            if (int(numbers[j] + numbers[i]) > int(numbers[i] + numbers[j]))
                numbers[i], numbers[j] = numbers[j], numbers[i]
        
        rez += numbers[i];

    if (rez.count("0") != len(rez) or len(rez) == 0):
        return "0";
    else:
        return rez;
