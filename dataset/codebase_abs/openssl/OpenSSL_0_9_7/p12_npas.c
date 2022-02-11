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
F_5 ( V_8 ) * V_9 , * V_10 ;
F_5 ( V_11 ) * V_12 ;
int V_13 , V_14 , V_15 , V_16 , V_17 ;
V_8 * V_18 , * V_19 ;
T_2 * V_20 = NULL , * V_21 = NULL ;
unsigned char V_22 [ V_23 ] ;
unsigned int V_24 ;
if ( ! ( V_9 = F_6 ( V_1 ) ) ) return 0 ;
if( ! ( V_10 = F_7 () ) ) return 0 ;
for ( V_13 = 0 ; V_13 < F_8 ( V_9 ) ; V_13 ++ ) {
V_18 = F_9 ( V_9 , V_13 ) ;
V_14 = F_10 ( V_18 -> type ) ;
if ( V_14 == V_25 ) {
V_12 = F_11 ( V_18 ) ;
} else if ( V_14 == V_26 ) {
V_12 = F_12 ( V_18 , V_2 , - 1 ) ;
F_13 ( V_18 -> V_27 . V_28 -> V_29 -> V_30 ,
& V_15 , & V_16 , & V_17 ) ;
} else continue;
if ( ! V_12 ) {
F_14 ( V_9 , V_31 ) ;
return 0 ;
}
if ( ! F_15 ( V_12 , V_2 , V_3 ) ) {
F_16 ( V_12 , V_32 ) ;
F_14 ( V_9 , V_31 ) ;
return 0 ;
}
if ( V_14 == V_25 ) V_19 = F_17 ( V_12 ) ;
else V_19 = F_18 ( V_15 , V_3 , - 1 , NULL ,
V_17 , V_16 , V_12 ) ;
F_16 ( V_12 , V_32 ) ;
if( ! V_19 ) {
F_14 ( V_9 , V_31 ) ;
return 0 ;
}
F_19 ( V_10 , V_19 ) ;
}
F_14 ( V_9 , V_31 ) ;
V_20 = V_1 -> V_33 -> V_27 . V_34 ;
if( ! ( V_1 -> V_33 -> V_27 . V_34 = F_20 () ) ) goto V_35;
if( ! F_21 ( V_1 , V_10 ) ) goto V_35;
if( ! F_22 ( V_1 , V_3 , - 1 , V_22 , & V_24 ) ) goto V_35;
if( ! ( V_21 = F_20 () ) ) goto V_35;
if( ! F_23 ( V_21 , V_22 , V_24 ) ) goto V_35;
F_24 ( V_1 -> V_22 -> V_36 -> V_37 ) ;
V_1 -> V_22 -> V_36 -> V_37 = V_21 ;
F_24 ( V_20 ) ;
return 1 ;
V_35:
F_24 ( V_1 -> V_33 -> V_27 . V_34 ) ;
F_24 ( V_21 ) ;
V_1 -> V_33 -> V_27 . V_34 = V_20 ;
return 0 ;
}
static int F_25 ( V_11 * V_38 , char * V_2 , char * V_3 )
{
T_3 * V_39 ;
T_4 * V_40 ;
int V_41 , V_42 , V_43 ;
if( F_26 ( V_38 ) != V_44 ) return 1 ;
if ( ! ( V_39 = F_27 ( V_38 -> V_45 . V_46 , V_2 , - 1 ) ) ) return 0 ;
F_13 ( V_38 -> V_45 . V_46 -> V_47 , & V_41 , & V_43 , & V_42 ) ;
if( ! ( V_40 = F_28 ( V_41 , NULL , V_3 , - 1 , NULL , V_42 ,
V_43 , V_39 ) ) ) return 0 ;
F_29 ( V_38 -> V_45 . V_46 ) ;
V_38 -> V_45 . V_46 = V_40 ;
return 1 ;
}
static int F_13 ( T_5 * V_48 , int * V_49 , int * V_50 , int * V_51 )
{
T_6 * V_52 ;
unsigned char * V_53 ;
V_53 = V_48 -> V_54 -> V_45 . V_55 -> V_34 ;
V_52 = F_30 ( NULL , & V_53 , V_48 -> V_54 -> V_45 . V_55 -> V_56 ) ;
* V_49 = F_10 ( V_48 -> V_30 ) ;
* V_50 = F_31 ( V_52 -> V_57 ) ;
* V_51 = V_52 -> V_58 -> V_56 ;
F_32 ( V_52 ) ;
return 0 ;
}
