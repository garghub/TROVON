int F_1 ( T_1 * V_1 , char * V_2 , char * V_3 )
{
if( ! V_1 ) {
F_2 ( V_4 , V_5 ) ;
return 0 ;
}
if ( ! F_3 ( V_1 , V_2 , - 1 ) ) {
F_2 ( V_4 , V_6 ) ;
return 0 ;
}
if ( ! F_4 ( V_1 , V_2 , V_3 ) ) {
F_2 ( V_4 , V_7 ) ;
return 0 ;
}
return 1 ;
}
static int F_4 ( T_1 * V_1 , char * V_2 , char * V_3 )
{
T_2 * V_8 , * V_9 , * V_10 ;
int V_11 , V_12 , V_13 , V_14 , V_15 ;
T_3 * V_16 , * V_17 ;
T_4 * V_18 = NULL , * V_19 = NULL ;
unsigned char V_20 [ V_21 ] ;
unsigned int V_22 ;
if ( ! ( V_8 = F_5 ( V_1 ) ) ) return 0 ;
if( ! ( V_9 = F_6 ( NULL ) ) ) return 0 ;
for ( V_11 = 0 ; V_11 < F_7 ( V_8 ) ; V_11 ++ ) {
V_16 = ( T_3 * ) F_8 ( V_8 , V_11 ) ;
V_12 = F_9 ( V_16 -> type ) ;
if ( V_12 == V_23 ) {
V_10 = F_10 ( V_16 ) ;
} else if ( V_12 == V_24 ) {
V_10 = F_11 ( V_16 , V_2 , - 1 ) ;
F_12 ( V_16 -> V_25 . V_26 -> V_27 -> V_28 ,
& V_13 , & V_14 , & V_15 ) ;
} else continue;
if ( ! V_10 ) {
F_13 ( V_8 , V_29 ) ;
return 0 ;
}
if ( ! F_14 ( V_10 , V_2 , V_3 ) ) {
F_13 ( V_10 , V_30 ) ;
F_13 ( V_8 , V_29 ) ;
return 0 ;
}
if ( V_12 == V_23 ) V_17 = F_15 ( V_10 ) ;
else V_17 = F_16 ( V_13 , V_3 , - 1 , NULL ,
V_15 , V_14 , V_10 ) ;
F_13 ( V_10 , V_30 ) ;
if( ! V_17 ) {
F_13 ( V_8 , V_29 ) ;
return 0 ;
}
F_17 ( V_9 , ( char * ) V_17 ) ;
}
F_13 ( V_8 , V_29 ) ;
V_18 = V_1 -> V_31 -> V_25 . V_32 ;
if( ! ( V_1 -> V_31 -> V_25 . V_32 = F_18 () ) ) goto V_33;
if( ! F_19 ( V_1 , V_9 ) ) goto V_33;
if( ! F_20 ( V_1 , V_3 , - 1 , V_20 , & V_22 ) ) goto V_33;
if( ! ( V_19 = F_18 () ) ) goto V_33;
if( ! F_21 ( V_19 , V_20 , V_22 ) ) goto V_33;
F_22 ( V_1 -> V_20 -> V_34 -> V_35 ) ;
V_1 -> V_20 -> V_34 -> V_35 = V_19 ;
F_22 ( V_18 ) ;
return 1 ;
V_33:
F_22 ( V_1 -> V_31 -> V_25 . V_32 ) ;
F_22 ( V_19 ) ;
V_1 -> V_31 -> V_25 . V_32 = V_18 ;
return 0 ;
}
static int F_14 ( T_2 * V_10 , char * V_2 , char * V_3 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_7 ( V_10 ) ; V_11 ++ ) {
if ( ! F_23 ( ( V_36 * ) F_8 ( V_10 , V_11 ) ,
V_2 , V_3 ) ) return 0 ;
}
return 1 ;
}
static int F_23 ( V_36 * V_37 , char * V_2 , char * V_3 )
{
T_5 * V_38 ;
T_6 * V_39 ;
int V_40 , V_41 , V_42 ;
if( F_24 ( V_37 ) != V_43 ) return 1 ;
if ( ! ( V_38 = F_25 ( V_37 , V_2 , - 1 ) ) ) return 0 ;
F_12 ( V_37 -> V_44 . V_45 -> V_46 , & V_40 , & V_42 , & V_41 ) ;
if( ! ( V_39 = F_26 ( V_40 , NULL , V_3 , - 1 , NULL , V_41 ,
V_42 , V_38 ) ) ) return 0 ;
F_27 ( V_37 -> V_44 . V_45 ) ;
V_37 -> V_44 . V_45 = V_39 ;
return 1 ;
}
static int F_12 ( T_7 * V_47 , int * V_48 , int * V_49 , int * V_50 )
{
T_8 * V_51 ;
unsigned char * V_52 ;
V_52 = V_47 -> V_53 -> V_44 . V_54 -> V_32 ;
V_51 = F_28 ( NULL , & V_52 , V_47 -> V_53 -> V_44 . V_54 -> V_55 ) ;
* V_48 = F_9 ( V_47 -> V_28 ) ;
* V_49 = F_29 ( V_51 -> V_56 ) ;
* V_50 = V_51 -> V_57 -> V_55 ;
F_30 ( V_51 ) ;
return 0 ;
}
