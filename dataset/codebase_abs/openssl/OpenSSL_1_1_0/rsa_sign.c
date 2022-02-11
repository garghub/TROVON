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
if ( V_5 -> V_16 -> V_17 ) {
return V_5 -> V_16 -> V_17 ( type , V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
if ( type == V_18 ) {
if ( V_2 != V_19 ) {
F_2 ( V_20 , V_21 ) ;
return ( 0 ) ;
}
V_8 = V_19 ;
V_13 = V_1 ;
} else {
V_6 . V_14 = & V_14 ;
V_6 . V_14 -> V_22 = F_3 ( type ) ;
if ( V_6 . V_14 -> V_22 == NULL ) {
F_2 ( V_20 , V_23 ) ;
return ( 0 ) ;
}
if ( F_4 ( V_6 . V_14 -> V_22 ) == 0 ) {
F_2 ( V_20 ,
V_24 ) ;
return ( 0 ) ;
}
V_7 . type = V_25 ;
V_7 . V_26 . V_27 = NULL ;
V_6 . V_14 -> V_7 = & V_7 ;
V_6 . V_15 = & V_15 ;
V_6 . V_15 -> V_28 = ( unsigned char * ) V_1 ;
V_6 . V_15 -> V_29 = V_2 ;
V_8 = F_5 ( & V_6 , NULL ) ;
}
V_9 = F_6 ( V_5 ) ;
if ( V_8 > ( V_9 - V_30 ) ) {
F_2 ( V_20 , V_31 ) ;
return ( 0 ) ;
}
if ( type != V_18 ) {
V_12 = F_7 ( ( unsigned int ) V_9 + 1 ) ;
if ( V_12 == NULL ) {
F_2 ( V_20 , V_32 ) ;
return ( 0 ) ;
}
V_11 = V_12 ;
F_5 ( & V_6 , & V_11 ) ;
V_13 = V_12 ;
}
V_8 = F_8 ( V_8 , V_13 , V_3 , V_5 , V_33 ) ;
if ( V_8 <= 0 )
V_10 = 0 ;
else
* V_4 = V_8 ;
if ( type != V_18 )
F_9 ( V_12 , ( unsigned int ) V_9 + 1 ) ;
return ( V_10 ) ;
}
static int F_10 ( T_2 * V_6 , const unsigned char * V_34 ,
int V_35 )
{
unsigned char * V_36 = NULL ;
int V_37 ;
int V_10 = 0 ;
V_37 = F_5 ( V_6 , & V_36 ) ;
if ( V_37 <= 0 )
return 0 ;
if ( V_37 == V_35 && ! memcmp ( V_34 , V_36 , V_37 ) )
V_10 = 1 ;
F_9 ( V_36 , V_37 ) ;
return V_10 ;
}
int F_11 ( int V_38 , const unsigned char * V_1 ,
unsigned int V_2 ,
unsigned char * V_39 , T_6 * V_40 ,
const unsigned char * V_41 , T_6 V_4 , T_1 * V_5 )
{
int V_8 , V_10 = 0 , V_42 ;
unsigned char * V_13 ;
T_2 * V_6 = NULL ;
if ( V_4 != ( unsigned int ) F_6 ( V_5 ) ) {
F_2 ( V_43 , V_44 ) ;
return ( 0 ) ;
}
if ( ( V_38 == V_18 ) && V_39 ) {
V_8 = F_12 ( ( int ) V_4 ,
V_41 , V_39 , V_5 , V_33 ) ;
if ( V_8 <= 0 )
return 0 ;
* V_40 = V_8 ;
return 1 ;
}
V_13 = F_7 ( ( unsigned int ) V_4 ) ;
if ( V_13 == NULL ) {
F_2 ( V_43 , V_32 ) ;
goto V_45;
}
if ( ( V_38 == V_18 ) && ( V_2 != V_19 ) ) {
F_2 ( V_43 , V_21 ) ;
goto V_45;
}
V_8 = F_12 ( ( int ) V_4 , V_41 , V_13 , V_5 , V_33 ) ;
if ( V_8 <= 0 )
goto V_45;
if ( V_38 == V_46 && V_8 == 18 && V_13 [ 0 ] == 0x04 && V_13 [ 1 ] == 0x10 ) {
if ( V_39 ) {
memcpy ( V_39 , V_13 + 2 , 16 ) ;
* V_40 = 16 ;
V_10 = 1 ;
} else if ( memcmp ( V_1 , V_13 + 2 , 16 ) ) {
F_2 ( V_43 , V_47 ) ;
} else {
V_10 = 1 ;
}
} else if ( V_38 == V_18 ) {
if ( ( V_8 != V_19 ) || memcmp ( V_13 , V_1 , V_19 ) )
F_2 ( V_43 , V_47 ) ;
else
V_10 = 1 ;
} else {
const unsigned char * V_11 = V_13 ;
V_6 = F_13 ( NULL , & V_11 , ( long ) V_8 ) ;
if ( V_6 == NULL )
goto V_45;
if ( V_11 != V_13 + V_8 || ! F_10 ( V_6 , V_13 , V_8 ) ) {
F_2 ( V_43 , V_47 ) ;
goto V_45;
}
if ( V_6 -> V_14 -> V_7
&& F_14 ( V_6 -> V_14 -> V_7 ) != V_25 ) {
F_2 ( V_43 , V_47 ) ;
goto V_45;
}
V_42 = F_15 ( V_6 -> V_14 -> V_22 ) ;
if ( V_42 != V_38 ) {
F_2 ( V_43 , V_48 ) ;
goto V_45;
}
if ( V_39 ) {
const T_7 * V_49 ;
V_49 = F_16 ( V_38 ) ;
if ( V_49 && ( F_17 ( V_49 ) != V_6 -> V_15 -> V_29 ) )
F_2 ( V_43 , V_50 ) ;
else {
memcpy ( V_39 , V_6 -> V_15 -> V_28 , V_6 -> V_15 -> V_29 ) ;
* V_40 = V_6 -> V_15 -> V_29 ;
V_10 = 1 ;
}
} else if ( ( ( unsigned int ) V_6 -> V_15 -> V_29 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_15 -> V_28 , V_2 ) != 0 ) ) {
F_2 ( V_43 , V_47 ) ;
} else
V_10 = 1 ;
}
V_45:
F_18 ( V_6 ) ;
F_9 ( V_13 , ( unsigned int ) V_4 ) ;
return ( V_10 ) ;
}
int F_19 ( int V_38 , const unsigned char * V_1 , unsigned int V_2 ,
const unsigned char * V_41 , unsigned int V_4 , T_1 * V_5 )
{
if ( V_5 -> V_16 -> V_51 ) {
return V_5 -> V_16 -> V_51 ( V_38 , V_1 , V_2 , V_41 , V_4 , V_5 ) ;
}
return F_11 ( V_38 , V_1 , V_2 , NULL , NULL , V_41 , V_4 , V_5 ) ;
}
