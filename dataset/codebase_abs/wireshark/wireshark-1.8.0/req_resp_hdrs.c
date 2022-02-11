T_1
F_1 ( T_2 * V_1 , const int V_2 , T_3 * V_3 ,
const T_1 V_4 , const T_1 V_5 )
{
T_4 V_6 ;
T_4 V_7 ;
T_4 V_8 , V_9 ;
int V_10 ;
T_5 * V_11 ;
long int V_12 ;
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
- 1 , & V_6 , TRUE ) ;
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
line = F_5 ( V_1 , V_7 , V_10 ) ;
if ( F_6 ( line , L_1 , 15 ) == 0 ) {
if ( sscanf ( line + 15 , L_2 , & V_12 ) == 1 )
V_13 = TRUE ;
} else if ( F_6 ( line , L_3 , 13 ) == 0 ) {
V_14 = TRUE ;
V_17 = line + 13 ;
while ( * V_17 == ' ' ) {
V_17 ++ ;
}
} else if ( F_6 ( line , L_4 , 11 ) == 0 ) {
V_11 = line + 11 ;
if( V_11 ) {
while( * V_11 == ' ' ) {
V_11 ++ ;
}
if( ! F_6 ( V_11 , L_5 , 10 ) ) {
V_16 = TRUE ;
}
}
} else if ( F_6 ( line , L_6 , 18 ) == 0 ) {
T_5 * V_22 ;
T_6 V_23 ;
V_11 = line + 18 ;
V_22 = V_11 ;
V_23 = ( T_6 ) strlen ( V_11 ) ;
while ( V_22 < V_11 + V_23 &&
( * V_22 == ' ' || * V_22 == '\t' ) )
V_22 ++ ;
if ( V_22 <= V_11 + V_23 ) {
if ( F_6 ( V_22 , L_7 , 7 )
== 0 ) {
V_15 = TRUE ;
}
}
}
}
}
}
if ( V_5 ) {
if ( V_13 ) {
if ( V_12 >= 128 * 1024 ) {
T_5 * V_24 ;
if ( V_14 &&
strncmp ( V_17 , L_8 , 15 ) == 0 ) {
return TRUE ;
}
V_24 = F_5 ( V_1 , 0 , sizeof( L_9 ) - 1 ) ;
if ( ( strncmp ( V_24 , L_10 , sizeof( L_10 ) - 1 ) == 0 ) ||
( strncmp ( V_24 , L_9 , sizeof( L_9 ) - 1 ) == 0 ) ) {
return TRUE ;
}
}
if ( ! F_7 ( V_1 , V_6 , V_12 ) ) {
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
} else if ( V_15 ) {
T_1 V_25 = FALSE ;
while ( ! V_25 ) {
T_6 V_26 = 0 ;
T_4 V_27 = 0 ;
T_5 * V_28 = NULL ;
T_5 * V_29 = NULL ;
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
- 1 , & V_27 , TRUE ) ;
if ( V_10 == - 1 &&
V_8 >=
V_9 ) {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
V_28 = F_5 ( V_1 , V_6 ,
V_10 ) ;
V_29 = V_28 ;
if ( ( V_29 = strchr ( V_29 , ';' ) ) ) {
* V_29 = '\0' ;
}
if ( sscanf ( V_28 , L_11 , & V_26 ) < 1 ) {
return TRUE ;
}
if ( V_26 > ( T_6 ) 1 << 31 ) {
return TRUE ;
}
if ( V_26 == 0 ) {
V_10 = F_4 ( V_1 ,
V_27 , - 1 , & V_27 , TRUE ) ;
if ( V_10 == - 1 &&
V_8 >=
V_9 ) {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
V_3 -> V_19 = V_27 ;
V_3 -> V_20 = 0 ;
V_25 = TRUE ;
} else {
if ( V_9 >
( T_4 ) V_26 ) {
V_6 = V_27
+ V_26 + 2 ;
} else {
V_3 -> V_19 = V_2 ;
V_3 -> V_20 = V_21 ;
return FALSE ;
}
}
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
V_3 -> V_20 = V_30 ;
return FALSE ;
}
}
return TRUE ;
}
