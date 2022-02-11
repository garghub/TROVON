static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
int V_6 ;
if( V_1 && ( V_1 -> V_7 == V_8 ) ) return 1 ;
if( ! V_1 || ! V_1 -> V_9 ) {
F_2 ( V_10 , V_11 ) ;
goto V_12;
}
V_6 = F_3 ( V_1 -> V_9 , V_13 , - 1 ) ;
if( V_6 < 0 ) return 1 ;
if( ! ( V_5 = F_4 ( V_1 -> V_9 , V_6 ) ) ||
! ( V_3 = F_5 ( V_5 ) ) ) {
F_2 ( V_10 , V_14 ) ;
goto V_12;
}
for( V_6 = 0 ; V_6 < F_6 ( V_3 ) ; V_6 ++ ) {
V_4 = F_7 ( V_3 , V_6 ) ;
if( ! F_8 ( V_2 , V_4 ) ) {
F_2 ( V_10 , V_15 ) ;
goto V_12;
}
}
F_9 ( V_3 ) ;
return 1 ;
V_12:
return 0 ;
}
static int F_10 ( T_1 * V_1 , T_2 * V_2 , int V_16 )
{
T_5 * V_17 ;
T_6 * V_18 = NULL ;
T_7 * V_19 ;
T_3 * V_4 = NULL ;
int V_6 ;
if( V_1 -> V_7 == V_8 ) return 1 ;
if( ! V_1 || ( ! V_1 -> V_20 && ! V_1 -> V_21 ) ) {
F_2 ( V_22 , V_23 ) ;
goto V_12;
}
if( V_1 -> V_20 ) V_17 = F_11 ( V_1 -> V_20 ) ;
else V_17 = F_12 ( V_1 -> V_21 ) ;
V_6 = - 1 ;
while( ( V_6 = F_13 ( V_17 ,
V_24 , V_6 ) ) >= 0 ) {
V_19 = F_14 ( V_17 , V_6 ) ;
V_18 = F_15 ( F_16 ( V_19 ) ) ;
if ( V_16 )
{
F_17 ( V_17 , V_6 ) ;
V_6 -- ;
}
if( ! V_18 || ! ( V_4 = F_18 () ) ) {
F_2 ( V_22 , V_15 ) ;
goto V_12;
}
V_4 -> V_25 . V_26 = V_18 ;
V_18 = NULL ;
V_4 -> type = V_27 ;
if( ! F_8 ( V_2 , V_4 ) ) {
F_2 ( V_22 , V_15 ) ;
goto V_12;
}
V_4 = NULL ;
}
return 1 ;
V_12:
F_19 ( V_4 ) ;
F_20 ( V_18 ) ;
return 0 ;
}
T_3 * F_21 ( T_8 * V_28 , T_1 * V_1 ,
T_9 * V_29 )
{
char V_30 = 0 ;
int type ;
T_3 * V_4 = NULL ;
char * V_31 , * V_32 ;
V_31 = V_29 -> V_31 ;
V_32 = V_29 -> V_32 ;
if( ! V_32 ) {
F_2 ( V_33 , V_34 ) ;
return NULL ;
}
if( ! ( V_4 = F_18 () ) ) {
F_2 ( V_33 , V_15 ) ;
return NULL ;
}
if( ! F_22 ( V_31 , L_1 ) ) {
V_30 = 1 ;
type = V_27 ;
} else if( ! F_22 ( V_31 , L_2 ) ) {
V_30 = 1 ;
type = V_35 ;
} else if( ! F_22 ( V_31 , L_3 ) ) {
V_30 = 1 ;
type = V_36 ;
} else if( ! F_22 ( V_31 , L_4 ) ) {
T_10 * V_37 ;
if( ! ( V_37 = F_23 ( V_32 , 0 ) ) ) {
F_2 ( V_33 , V_38 ) ;
F_24 ( 2 , L_5 , V_32 ) ;
goto V_12;
}
V_4 -> V_25 . V_39 = V_37 ;
type = V_40 ;
} else if( ! F_22 ( V_31 , L_6 ) ) {
int V_41 , V_42 , V_43 , V_44 ;
unsigned char V_45 [ 4 ] ;
if( ( sscanf ( V_32 , L_7 , & V_41 , & V_42 , & V_43 , & V_44 ) != 4 ) ||
( V_41 < 0 ) || ( V_41 > 255 ) || ( V_42 < 0 ) || ( V_42 > 255 ) ||
( V_43 < 0 ) || ( V_43 > 255 ) || ( V_44 < 0 ) || ( V_44 > 255 ) ) {
F_2 ( V_33 , V_46 ) ;
F_24 ( 2 , L_5 , V_32 ) ;
goto V_12;
}
V_45 [ 0 ] = V_41 ; V_45 [ 1 ] = V_42 ; V_45 [ 2 ] = V_43 ; V_45 [ 3 ] = V_44 ;
if( ! ( V_4 -> V_25 . V_45 = F_25 () ) ||
! F_26 ( V_4 -> V_25 . V_45 , V_45 , 4 ) ) {
F_2 ( V_33 , V_15 ) ;
goto V_12;
}
type = V_47 ;
} else {
F_2 ( V_33 , V_48 ) ;
F_24 ( 2 , L_8 , V_31 ) ;
goto V_12;
}
if( V_30 ) {
if( ! ( V_4 -> V_25 . V_26 = F_27 () ) ||
! F_26 ( V_4 -> V_25 . V_26 , ( unsigned char * ) V_32 ,
strlen ( V_32 ) ) ) {
F_2 ( V_33 , V_15 ) ;
goto V_12;
}
}
V_4 -> type = type ;
return V_4 ;
V_12:
F_19 ( V_4 ) ;
return NULL ;
}
