int F_1 ( int type , const unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_3 , unsigned int * V_4 , T_1 * V_5 )
{
T_2 V_6 ;
T_3 V_7 ;
int V_8 , V_9 , V_10 = 1 ;
unsigned char * V_11 , * V_12 = NULL ;
const unsigned char * V_13 = NULL ;
T_4 V_14 ;
T_5 V_15 ;
#ifdef F_2
if ( F_3 () && ! ( V_5 -> V_16 -> V_17 & V_18 )
&& ! ( V_5 -> V_17 & V_19 ) ) {
F_4 ( V_20 , V_21 ) ;
return 0 ;
}
#endif
if ( ( V_5 -> V_17 & V_22 ) && V_5 -> V_16 -> V_23 ) {
return V_5 -> V_16 -> V_23 ( type , V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
if ( type == V_24 ) {
if ( V_2 != V_25 ) {
F_4 ( V_20 , V_26 ) ;
return ( 0 ) ;
}
V_8 = V_25 ;
V_13 = V_1 ;
} else {
V_6 . V_14 = & V_14 ;
V_6 . V_14 -> V_27 = F_5 ( type ) ;
if ( V_6 . V_14 -> V_27 == NULL ) {
F_4 ( V_20 , V_28 ) ;
return ( 0 ) ;
}
if ( V_6 . V_14 -> V_27 -> V_29 == 0 ) {
F_4 ( V_20 ,
V_30 ) ;
return ( 0 ) ;
}
V_7 . type = V_31 ;
V_7 . V_32 . V_33 = NULL ;
V_6 . V_14 -> V_7 = & V_7 ;
V_6 . V_15 = & V_15 ;
V_6 . V_15 -> V_34 = ( unsigned char * ) V_1 ;
V_6 . V_15 -> V_29 = V_2 ;
V_8 = F_6 ( & V_6 , NULL ) ;
}
V_9 = F_7 ( V_5 ) ;
if ( V_8 > ( V_9 - V_35 ) ) {
F_4 ( V_20 , V_36 ) ;
return ( 0 ) ;
}
if ( type != V_24 ) {
V_12 = ( unsigned char * ) F_8 ( ( unsigned int ) V_9 + 1 ) ;
if ( V_12 == NULL ) {
F_4 ( V_20 , V_37 ) ;
return ( 0 ) ;
}
V_11 = V_12 ;
F_6 ( & V_6 , & V_11 ) ;
V_13 = V_12 ;
}
V_8 = F_9 ( V_8 , V_13 , V_3 , V_5 , V_38 ) ;
if ( V_8 <= 0 )
V_10 = 0 ;
else
* V_4 = V_8 ;
if ( type != V_24 ) {
F_10 ( V_12 , ( unsigned int ) V_9 + 1 ) ;
F_11 ( V_12 ) ;
}
return ( V_10 ) ;
}
static int F_12 ( T_2 * V_6 , const unsigned char * V_39 ,
int V_40 )
{
unsigned char * V_41 = NULL ;
int V_42 ;
int V_10 = 0 ;
V_42 = F_6 ( V_6 , & V_41 ) ;
if ( V_42 <= 0 )
return 0 ;
if ( V_42 == V_40 && ! memcmp ( V_39 , V_41 , V_42 ) )
V_10 = 1 ;
F_10 ( V_41 , V_42 ) ;
F_11 ( V_41 ) ;
return V_10 ;
}
int F_13 ( int V_43 , const unsigned char * V_1 ,
unsigned int V_2 ,
unsigned char * V_44 , T_6 * V_45 ,
const unsigned char * V_46 , T_6 V_4 , T_1 * V_5 )
{
int V_8 , V_10 = 0 , V_47 ;
unsigned char * V_13 ;
T_2 * V_6 = NULL ;
#ifdef F_2
if ( F_3 () && ! ( V_5 -> V_16 -> V_17 & V_18 )
&& ! ( V_5 -> V_17 & V_19 ) ) {
F_4 ( V_48 , V_21 ) ;
return 0 ;
}
#endif
if ( V_4 != ( unsigned int ) F_7 ( V_5 ) ) {
F_4 ( V_48 , V_49 ) ;
return ( 0 ) ;
}
if ( ( V_43 == V_24 ) && V_44 ) {
V_8 = F_14 ( ( int ) V_4 ,
V_46 , V_44 , V_5 , V_38 ) ;
if ( V_8 <= 0 )
return 0 ;
* V_45 = V_8 ;
return 1 ;
}
V_13 = ( unsigned char * ) F_8 ( ( unsigned int ) V_4 ) ;
if ( V_13 == NULL ) {
F_4 ( V_48 , V_37 ) ;
goto V_50;
}
if ( ( V_43 == V_24 ) && ( V_2 != V_25 ) ) {
F_4 ( V_48 , V_26 ) ;
goto V_50;
}
V_8 = F_14 ( ( int ) V_4 , V_46 , V_13 , V_5 , V_38 ) ;
if ( V_8 <= 0 )
goto V_50;
if ( V_43 == V_51 && V_8 == 18 && V_13 [ 0 ] == 0x04 && V_13 [ 1 ] == 0x10 ) {
if ( V_44 ) {
memcpy ( V_44 , V_13 + 2 , 16 ) ;
* V_45 = 16 ;
V_10 = 1 ;
} else if ( memcmp ( V_1 , V_13 + 2 , 16 ) )
F_4 ( V_48 , V_52 ) ;
else
V_10 = 1 ;
}
if ( V_43 == V_24 ) {
if ( ( V_8 != V_25 ) || memcmp ( V_13 , V_1 , V_25 ) )
F_4 ( V_48 , V_52 ) ;
else
V_10 = 1 ;
} else {
const unsigned char * V_11 = V_13 ;
V_6 = F_15 ( NULL , & V_11 , ( long ) V_8 ) ;
if ( V_6 == NULL )
goto V_50;
if ( V_11 != V_13 + V_8 || ! F_12 ( V_6 , V_13 , V_8 ) ) {
F_4 ( V_48 , V_52 ) ;
goto V_50;
}
if ( V_6 -> V_14 -> V_7
&& F_16 ( V_6 -> V_14 -> V_7 ) != V_31 ) {
F_4 ( V_48 , V_52 ) ;
goto V_50;
}
V_47 = F_17 ( V_6 -> V_14 -> V_27 ) ;
#ifdef F_18
fprintf ( V_53 , L_1 , F_19 ( V_47 ) ,
F_19 ( V_43 ) ) ;
#endif
if ( V_47 != V_43 ) {
if ( ( ( V_43 == V_54 ) &&
( V_47 == V_55 ) ) ||
( ( V_43 == V_56 ) &&
( V_47 == V_57 ) ) ) {
#if ! F_20 ( V_58 ) && ! F_20 ( V_59 )
fprintf ( V_53 ,
L_2 ) ;
#endif
} else {
F_4 ( V_48 , V_60 ) ;
goto V_50;
}
}
if ( V_44 ) {
const T_7 * V_61 ;
V_61 = F_21 ( V_43 ) ;
if ( V_61 && ( F_22 ( V_61 ) != V_6 -> V_15 -> V_29 ) )
F_4 ( V_48 , V_62 ) ;
else {
memcpy ( V_44 , V_6 -> V_15 -> V_34 , V_6 -> V_15 -> V_29 ) ;
* V_45 = V_6 -> V_15 -> V_29 ;
V_10 = 1 ;
}
} else if ( ( ( unsigned int ) V_6 -> V_15 -> V_29 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_15 -> V_34 , V_2 ) != 0 ) ) {
F_4 ( V_48 , V_52 ) ;
} else
V_10 = 1 ;
}
V_50:
if ( V_6 != NULL )
F_23 ( V_6 ) ;
if ( V_13 != NULL ) {
F_10 ( V_13 , ( unsigned int ) V_4 ) ;
F_11 ( V_13 ) ;
}
return ( V_10 ) ;
}
int F_24 ( int V_43 , const unsigned char * V_1 , unsigned int V_2 ,
const unsigned char * V_46 , unsigned int V_4 , T_1 * V_5 )
{
if ( ( V_5 -> V_17 & V_22 ) && V_5 -> V_16 -> V_63 ) {
return V_5 -> V_16 -> V_63 ( V_43 , V_1 , V_2 , V_46 , V_4 , V_5 ) ;
}
return F_13 ( V_43 , V_1 , V_2 , NULL , NULL , V_46 , V_4 , V_5 ) ;
}
