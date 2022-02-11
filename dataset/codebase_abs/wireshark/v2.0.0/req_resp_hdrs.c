T_1
F_1 ( T_2 * V_1 , const int V_2 , T_3 * V_3 ,
const T_1 V_4 , const T_1 V_5 )
{
T_4 V_6 ;
T_4 V_7 ;
T_4 V_8 , V_9 ;
int V_10 ;
T_5 * V_11 ;
int V_12 ;
T_1 V_13 = FALSE ;
T_1 V_14 = FALSE ;
T_1 V_15 = FALSE ;
T_1 V_16 = FALSE ;
T_5 * line ;
T_5 * V_17 = NULL ;
if ( V_4 && V_3 -> V_18 ) {
V_6 = V_2 ;
for (; ; ) {
V_7 = V_6 ;
V_9 =
F_2 ( V_1 , V_6 ) ;
if ( V_9 < 1 ) {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
V_8 = F_3 ( V_1 ,
V_6 ) ;
V_10 = F_4 ( V_1 , V_6 ,
V_8 , & V_6 , TRUE ) ;
if ( V_10 == - 1 &&
V_8 >= V_9 ) {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
if ( V_10 == 0 ) {
break;
}
if ( V_5 ) {
T_6 V_22 = F_5 ( V_1 , V_7 ) ;
if ( ! ( V_22 == 'c' || V_22 == 'C' ||
V_22 == 't' || V_22 == 'T' ) ) {
continue;
}
line = F_6 ( F_7 () , V_1 , V_7 , V_10 , V_23 | V_24 ) ;
if ( F_8 ( line , L_1 , 15 ) == 0 ) {
if ( sscanf ( line + 15 , L_2 , & V_12 ) == 1 )
V_13 = TRUE ;
} else if ( F_8 ( line , L_3 , 13 ) == 0 ) {
V_14 = TRUE ;
V_17 = line + 13 ;
while ( * V_17 == ' ' ) {
V_17 ++ ;
}
} else if ( F_8 ( line , L_4 , 11 ) == 0 ) {
V_11 = line + 11 ;
if( V_11 ) {
while( * V_11 == ' ' ) {
V_11 ++ ;
}
if( ! F_8 ( V_11 , L_5 , 10 ) ) {
V_16 = TRUE ;
}
}
} else if ( F_8 ( line , L_6 , 18 ) == 0 ) {
T_5 * V_25 ;
T_7 V_26 ;
V_11 = line + 18 ;
V_25 = V_11 ;
V_26 = ( T_7 ) strlen ( V_11 ) ;
while ( V_25 < V_11 + V_26 &&
( * V_25 == ' ' || * V_25 == '\t' ) )
V_25 ++ ;
if ( V_25 <= V_11 + V_26 ) {
if ( F_8 ( V_25 , L_7 , 7 )
== 0 ) {
V_15 = TRUE ;
}
}
}
}
}
}
if ( V_5 ) {
if ( V_15 ) {
T_1 V_27 = FALSE ;
while ( ! V_27 ) {
T_7 V_28 = 0 ;
T_4 V_29 = 0 ;
T_5 * V_30 = NULL ;
T_5 * V_31 = NULL ;
V_9 =
F_2 ( V_1 ,
V_6 ) ;
if ( V_9 < 1 ) {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
V_8 = F_3 ( V_1 ,
V_6 ) ;
V_10 = F_4 ( V_1 , V_6 ,
V_8 , & V_29 , TRUE ) ;
if ( V_10 == - 1 &&
V_8 >=
V_9 ) {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
V_30 = F_9 ( F_7 () , V_1 , V_6 ,
V_10 ) ;
V_31 = V_30 ;
if ( ( V_31 = strchr ( V_31 , ';' ) ) ) {
* V_31 = '\0' ;
}
if ( sscanf ( V_30 , L_8 , & V_28 ) < 1 ) {
return TRUE ;
}
if ( V_28 > 1U << 31 ) {
return TRUE ;
}
if ( V_28 == 0 ) {
V_10 = F_4 ( V_1 ,
V_29 , V_8 , & V_29 , TRUE ) ;
if ( V_10 == - 1 &&
V_8 >=
V_9 ) {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
V_3 -> V_19 = V_29 ;
V_3 -> V_20 = 0 ;
V_27 = TRUE ;
} else {
if ( V_9 >
( T_4 ) V_28 ) {
V_6 = V_29
+ V_28 + 2 ;
} else {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
}
}
} else if ( V_13 ) {
if ( V_12 >= 128 * 1024 ) {
T_5 * V_32 ;
if ( V_14 &&
strncmp ( V_17 , L_9 , 15 ) == 0 ) {
return TRUE ;
}
V_32 = F_9 ( F_7 () , V_1 , 0 , sizeof( L_10 ) - 1 ) ;
if ( ( strncmp ( V_32 , L_11 , sizeof( L_11 ) - 1 ) == 0 ) ||
( strncmp ( V_32 , L_10 , sizeof( L_10 ) - 1 ) == 0 ) ) {
return TRUE ;
}
}
if ( ! F_10 ( V_1 , V_6 , V_12 ) ) {
V_8 = F_3 ( V_1 ,
V_6 ) ;
V_9 =
F_2 ( V_1 , V_6 ) ;
if ( V_8 < V_9 ) {
return TRUE ;
}
if ( V_8 == - 1 )
V_8 = 0 ;
V_3 -> V_19 = V_2 ;
V_3 -> V_20 =
V_12 - V_8 ;
return FALSE ;
}
} else if ( V_14 && V_3 -> V_18 ) {
V_8 = F_3 ( V_1 , V_6 ) ;
V_9 = F_2 ( V_1 , V_6 ) ;
if ( V_8 < V_9 ) {
return TRUE ;
}
if ( V_16 ) {
return TRUE ;
}
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_33 ;
return FALSE ;
}
}
return TRUE ;
}
