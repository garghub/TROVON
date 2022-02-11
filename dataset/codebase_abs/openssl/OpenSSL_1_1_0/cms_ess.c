int F_1 ( T_1 * V_1 , T_2 * * V_2 )
{
T_3 * V_3 ;
T_2 * V_4 = NULL ;
if ( V_2 )
* V_2 = NULL ;
V_3 = F_2 ( V_1 ,
F_3
( V_5 ) , - 3 ,
V_6 ) ;
if ( ! V_3 )
return 0 ;
V_4 = F_4 ( V_3 , F_5 ( T_2 ) ) ;
if ( ! V_4 )
return - 1 ;
if ( V_2 )
* V_2 = V_4 ;
else
F_6 ( V_4 ) ;
return 1 ;
}
int F_7 ( T_1 * V_1 , T_2 * V_4 )
{
unsigned char * V_7 = NULL ;
int V_8 , V_9 = 0 ;
V_8 = F_8 ( V_4 , & V_7 ) ;
if ( V_8 < 0 )
goto V_10;
if ( ! F_9 ( V_1 , V_5 ,
V_6 , V_7 , V_8 ) )
goto V_10;
V_9 = 1 ;
V_10:
if ( ! V_9 )
F_10 ( V_11 , V_12 ) ;
F_11 ( V_7 ) ;
return V_9 ;
}
static int F_12 ( T_1 * V_1 ,
unsigned char * V_13 , unsigned int * V_14 )
{
const T_4 * V_15 ;
V_15 = F_13 ( V_1 -> V_16 -> V_17 ) ;
if ( V_15 == NULL )
return 0 ;
if ( ! F_14 ( F_5 ( V_18 ) , V_15 ,
V_1 -> V_19 , V_13 , V_14 ) )
return 0 ;
return 1 ;
}
int F_15 ( T_1 * V_20 , T_1 * V_21 )
{
unsigned char V_13 [ V_22 ] ;
unsigned int V_14 ;
if ( ! F_12 ( V_21 , V_13 , & V_14 ) ) {
F_10 ( V_23 , V_24 ) ;
return 0 ;
}
if ( ! F_9 ( V_20 , V_25 ,
V_26 , V_13 , V_14 ) ) {
F_10 ( V_23 , V_12 ) ;
return 0 ;
}
return 1 ;
}
int F_16 ( T_5 * V_27 , T_5 * V_28 )
{
int V_9 = 0 , V_29 ;
T_2 * V_4 = NULL ;
T_6 * V_30 = NULL ;
F_17 ( T_1 ) * V_31 , * V_32 ;
T_1 * V_1 , * V_33 = NULL ;
T_7 * V_34 , * * V_35 ;
T_8 * V_36 ;
unsigned char V_13 [ V_22 ] ;
unsigned int V_14 ;
V_32 = F_18 ( V_28 ) ;
V_31 = F_18 ( V_27 ) ;
if ( ! V_32 || ! V_31 )
goto V_37;
if ( F_19 ( V_31 ) != 1 ) {
F_10 ( V_38 , V_39 ) ;
goto V_37;
}
if ( F_20 ( F_21 ( V_27 ) ) != V_40 ) {
F_10 ( V_38 , V_41 ) ;
goto V_37;
}
V_35 = F_22 ( V_27 ) ;
if ( ! V_35 || ! * V_35 ) {
F_10 ( V_38 , V_42 ) ;
goto V_37;
}
V_30 = F_4 ( * V_35 , F_5 ( T_6 ) ) ;
if ( ! V_30 ) {
F_10 ( V_38 , V_43 ) ;
goto V_37;
}
for ( V_29 = 0 ; V_29 < F_19 ( V_32 ) ; V_29 ++ ) {
V_33 = F_23 ( V_32 , V_29 ) ;
if ( ! F_24 ( V_33 -> V_44 , V_30 -> V_45 ) )
break;
}
if ( V_29 == F_19 ( V_32 ) ) {
F_10 ( V_38 , V_46 ) ;
goto V_37;
}
V_1 = F_23 ( V_31 , 0 ) ;
V_34 = F_2 ( V_1 ,
F_3
( V_25 ) , - 3 ,
V_26 ) ;
if ( ! V_34 ) {
F_10 ( V_38 , V_47 ) ;
goto V_37;
}
if ( ! F_12 ( V_33 , V_13 , & V_14 ) ) {
F_10 ( V_38 , V_24 ) ;
goto V_37;
}
if ( V_14 != ( unsigned int ) V_34 -> V_48 ) {
F_10 ( V_38 , V_49 ) ;
goto V_37;
}
if ( memcmp ( V_13 , V_34 -> V_50 , V_14 ) ) {
F_10 ( V_38 ,
V_51 ) ;
goto V_37;
}
V_36 = F_2 ( V_33 ,
F_3 ( V_52 ) ,
- 3 , V_53 ) ;
if ( ! V_36 ) {
F_10 ( V_38 , V_54 ) ;
goto V_37;
}
if ( F_25 ( V_36 , V_30 -> V_55 ) ) {
F_10 ( V_38 , V_56 ) ;
goto V_37;
}
if ( F_1 ( V_33 , & V_4 ) <= 0 ) {
F_10 ( V_38 , V_57 ) ;
goto V_37;
}
if ( F_24 ( V_4 -> V_58 ,
V_30 -> V_58 ) ) {
F_10 ( V_38 , V_59 ) ;
goto V_37;
}
V_9 = 1 ;
V_37:
F_6 ( V_4 ) ;
F_26 ( V_30 , T_6 ) ;
return V_9 ;
}
T_7 * F_27 ( T_1 * V_1 )
{
T_6 V_30 ;
T_2 * V_4 = NULL ;
T_8 * V_60 ;
T_7 * V_61 = NULL ;
if ( F_1 ( V_1 , & V_4 ) <= 0 ) {
F_10 ( V_62 , V_57 ) ;
goto V_37;
}
V_60 = F_2 ( V_1 ,
F_3 ( V_52 ) ,
- 3 , V_53 ) ;
if ( ! V_60 ) {
F_10 ( V_62 , V_54 ) ;
goto V_37;
}
V_30 . V_63 = 1 ;
V_30 . V_55 = V_60 ;
V_30 . V_58 = V_4 -> V_58 ;
V_30 . V_45 = V_1 -> V_44 ;
V_61 = F_28 ( & V_30 , F_5 ( T_6 ) , NULL ) ;
V_37:
F_6 ( V_4 ) ;
return V_61 ;
}
