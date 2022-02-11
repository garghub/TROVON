static int F_1 ( unsigned char * V_1 , T_1 * V_2 ,
T_2 * V_3 )
{
unsigned char V_4 [ 128 ] ;
int V_5 , V_6 ;
V_6 = F_2 ( V_4 , V_2 , V_3 ) ;
if ( ! V_6 )
return 0 ;
memset ( V_1 , 0 , 128 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_1 [ V_5 ] = V_4 [ V_6 - 1 - V_5 ] ;
}
return V_6 ;
}
static int F_3 ( T_1 * V_7 , T_3 * V_8 ,
unsigned char * V_9 )
{
unsigned char V_10 [ 128 ] ;
int V_11 ;
T_4 V_12 ;
T_2 * V_3 = F_4 () ;
if ( ! V_3 )
return 0 ;
memset ( V_10 , 0 , 128 ) ;
V_3 -> V_13 = F_5 ( V_8 -> V_14 . V_15 -> V_13 ) ;
V_3 -> V_16 = F_5 ( V_8 -> V_14 . V_15 -> V_16 ) ;
V_3 -> V_7 = F_5 ( V_7 ) ;
V_11 =
F_1 ( V_10 , ( ( V_17 * ) ( F_6 ( V_8 ) ) ) -> V_2 ,
V_3 ) ;
F_7 ( V_3 ) ;
if ( ! V_11 )
return 0 ;
F_8 ( & V_12 , & V_18 ) ;
F_9 ( & V_12 ) ;
F_10 ( & V_12 , V_10 , 128 ) ;
F_11 ( & V_12 , V_9 ) ;
F_12 ( & V_12 ) ;
return 1 ;
}
int F_13 ( T_5 * V_19 , unsigned char * V_20 , T_6 * V_21 )
{
T_3 * V_8 = F_14 ( V_19 ) ;
T_3 * V_22 = F_15 ( V_19 ) ;
* V_21 = 32 ;
if ( V_20 == NULL )
return 1 ;
return F_3 ( F_16 ( V_22 ) , V_8 , V_20 ) ;
}
int F_17 ( T_5 * V_19 , unsigned char * V_23 ,
T_6 * V_24 , const unsigned char * V_20 ,
T_6 V_25 )
{
T_7 * V_26 = NULL ;
unsigned char V_9 [ 32 ] , V_27 [ 8 ] , V_28 [ 44 ] ;
const struct V_29 * V_30 = F_18 ( NULL ) ;
T_3 * V_8 = F_15 ( V_19 ) ;
struct V_31 * V_32 = F_19 ( V_19 ) ;
T_8 V_33 ;
int V_34 = 1 ;
T_3 * V_22 = F_14 ( V_19 ) ;
if ( ! F_20 ( V_35 )
&& V_30 == V_36 ) {
V_30 = V_36 + 1 ;
}
if ( V_22 ) {
V_34 = 0 ;
if ( ! F_16 ( V_22 ) ) {
F_21 ( V_37 ,
V_38 ) ;
goto V_39;
}
} else {
V_34 = 1 ;
if ( V_23 ) {
V_22 = F_22 () ;
F_23 ( V_22 , F_24 ( V_8 ) , F_25 () ) ;
F_26 ( V_22 , V_8 ) ;
if ( ! F_27 ( F_6 ( V_22 ) ) ) {
goto V_39;
}
}
}
if ( V_23 )
F_3 ( F_16 ( V_22 ) , V_8 , V_9 ) ;
if ( V_32 -> V_40 ) {
memcpy ( V_27 , V_32 -> V_40 , 8 ) ;
} else if ( V_23 ) {
if ( F_28 ( V_27 , 8 ) <= 0 ) {
F_21 ( V_37 ,
V_41 ) ;
goto V_39;
}
}
if ( V_23 ) {
F_29 ( & V_33 , V_30 -> V_42 ) ;
F_30 ( & V_33 , V_9 , V_27 , V_20 , V_28 ) ;
}
V_26 = F_31 () ;
if ( ! V_26 ) {
goto V_43;
}
if ( ! F_32 ( V_26 -> V_44 -> V_45 , V_27 , 8 ) ) {
goto V_43;
}
if ( ! F_32 ( V_26 -> V_46 -> V_47 , V_28 + 40 , 4 ) ) {
goto V_43;
}
if ( ! F_32
( V_26 -> V_46 -> V_48 , V_28 + 8 , 32 ) ) {
goto V_43;
}
if ( V_34 ) {
if ( ! F_33
( & V_26 -> V_44 -> V_49 , V_23 ? V_22 : V_8 ) ) {
F_21 ( V_37 ,
V_50 ) ;
goto V_39;
}
if ( V_23 )
F_34 ( V_22 ) ;
}
F_35 ( V_26 -> V_44 -> V_51 ) ;
V_26 -> V_44 -> V_51 = F_36 ( V_30 -> V_52 ) ;
* V_24 = F_37 ( V_26 , V_23 ? & V_23 : NULL ) ;
if ( * V_24 <= 0 ) {
F_21 ( V_37 ,
V_53 ) ;
goto V_39;
}
if ( ! V_34 ) {
if ( F_38 ( V_19 , - 1 , - 1 , V_54 , 3 , NULL ) <=
0 ) {
F_21 ( V_37 , V_55 ) ;
goto V_39;
}
}
F_39 ( V_26 ) ;
return 1 ;
V_43:
if ( V_34 ) {
F_34 ( V_22 ) ;
}
F_21 ( V_37 , V_56 ) ;
V_39:
F_39 ( V_26 ) ;
return - 1 ;
}
int F_40 ( T_5 * V_19 , unsigned char * V_20 ,
T_6 * V_25 , const unsigned char * V_57 ,
T_6 V_58 )
{
const unsigned char * V_16 = V_57 ;
T_7 * V_26 = NULL ;
unsigned char V_59 [ 44 ] ;
unsigned char V_60 [ 32 ] ;
T_8 V_33 ;
const struct V_29 * V_30 = NULL ;
T_3 * V_61 = NULL , * V_62 = NULL ;
T_3 * V_63 = F_15 ( V_19 ) ;
if ( ! V_20 ) {
* V_25 = 32 ;
return 1 ;
}
V_26 = F_41 ( NULL , ( const unsigned char * * ) & V_16 , V_58 ) ;
if ( ! V_26 ) {
F_21 ( V_64 ,
V_65 ) ;
return 0 ;
}
V_61 = F_42 ( V_26 -> V_44 -> V_49 ) ;
if ( V_61 ) {
if ( F_43 ( V_19 , V_61 ) <= 0 ) {
F_21 ( V_64 ,
V_66 ) ;
goto V_39;
}
} else {
if ( F_38 ( V_19 , - 1 , - 1 , V_54 , 3 , NULL ) <=
0 ) {
F_21 ( V_64 , V_55 ) ;
goto V_39;
}
}
V_62 = F_14 ( V_19 ) ;
if ( ! V_62 ) {
F_21 ( V_64 , V_67 ) ;
goto V_39;
}
V_30 = F_18 ( V_26 -> V_44 -> V_51 ) ;
if ( ! V_30 ) {
goto V_39;
}
F_29 ( & V_33 , V_30 -> V_42 ) ;
F_44 ( V_26 -> V_44 -> V_45 -> V_68 == 8 ) ;
memcpy ( V_59 , V_26 -> V_44 -> V_45 -> V_32 , 8 ) ;
F_44 ( V_26 -> V_46 -> V_48 -> V_68 == 32 ) ;
memcpy ( V_59 + 8 , V_26 -> V_46 -> V_48 -> V_32 , 32 ) ;
F_44 ( V_26 -> V_46 -> V_47 -> V_68 == 4 ) ;
memcpy ( V_59 + 40 , V_26 -> V_46 -> V_47 -> V_32 , 4 ) ;
F_3 ( F_16 ( V_63 ) , V_62 , V_60 ) ;
if ( ! F_45 ( & V_33 , V_60 , V_59 , V_20 ) ) {
F_21 ( V_64 ,
V_69 ) ;
goto V_39;
}
F_34 ( V_61 ) ;
F_39 ( V_26 ) ;
return 1 ;
V_39:
F_34 ( V_61 ) ;
F_39 ( V_26 ) ;
return - 1 ;
}
