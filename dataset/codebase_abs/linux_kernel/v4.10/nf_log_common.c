int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
T_1 V_5 , int V_6 , unsigned int V_7 )
{
struct V_8 V_9 ;
const struct V_8 * V_10 ;
if ( V_5 == V_11 )
F_2 ( V_2 , L_1 ) ;
else
F_2 ( V_2 , L_2 ) ;
if ( V_6 )
goto V_12;
V_10 = F_3 ( V_4 , V_7 , sizeof( V_9 ) , & V_9 ) ;
if ( V_10 == NULL ) {
F_2 ( V_2 , L_3 , V_4 -> V_13 - V_7 ) ;
return 1 ;
}
F_2 ( V_2 , L_4 ,
F_4 ( V_10 -> V_14 ) , F_4 ( V_10 -> V_15 ) , F_4 ( V_10 -> V_13 ) ) ;
V_12:
return 0 ;
}
int F_5 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
T_1 V_5 , int V_6 , unsigned int V_7 ,
unsigned int V_16 )
{
struct V_17 V_18 ;
const struct V_17 * V_19 ;
F_2 ( V_2 , L_5 ) ;
if ( V_6 )
return 0 ;
V_19 = F_3 ( V_4 , V_7 , sizeof( V_18 ) , & V_18 ) ;
if ( V_19 == NULL ) {
F_2 ( V_2 , L_3 , V_4 -> V_13 - V_7 ) ;
return 1 ;
}
F_2 ( V_2 , L_6 ,
F_4 ( V_19 -> V_14 ) , F_4 ( V_19 -> V_15 ) ) ;
if ( V_16 & V_20 ) {
F_2 ( V_2 , L_7 ,
F_6 ( V_19 -> V_21 ) , F_6 ( V_19 -> V_22 ) ) ;
}
F_2 ( V_2 , L_8 , F_4 ( V_19 -> V_23 ) ) ;
F_2 ( V_2 , L_9 , ( V_24 ) ( F_6 ( F_7 ( V_19 ) &
V_25 ) >> 22 ) ) ;
if ( V_19 -> V_26 )
F_2 ( V_2 , L_10 ) ;
if ( V_19 -> V_27 )
F_2 ( V_2 , L_11 ) ;
if ( V_19 -> V_28 )
F_2 ( V_2 , L_12 ) ;
if ( V_19 -> V_29 )
F_2 ( V_2 , L_13 ) ;
if ( V_19 -> V_30 )
F_2 ( V_2 , L_14 ) ;
if ( V_19 -> V_31 )
F_2 ( V_2 , L_15 ) ;
if ( V_19 -> V_32 )
F_2 ( V_2 , L_16 ) ;
if ( V_19 -> V_33 )
F_2 ( V_2 , L_17 ) ;
F_2 ( V_2 , L_18 , F_4 ( V_19 -> V_34 ) ) ;
if ( ( V_16 & V_35 ) && V_19 -> V_36 * 4 > sizeof( struct V_17 ) ) {
V_24 V_37 [ 60 - sizeof( struct V_17 ) ] ;
const V_24 * V_38 ;
unsigned int V_39 ;
unsigned int V_40 = V_19 -> V_36 * 4 - sizeof( struct V_17 ) ;
V_38 = F_3 ( V_4 , V_7 + sizeof( struct V_17 ) ,
V_40 , V_37 ) ;
if ( V_38 == NULL ) {
F_2 ( V_2 , L_19 ) ;
return 1 ;
}
F_2 ( V_2 , L_20 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_2 ( V_2 , L_21 , V_38 [ V_39 ] ) ;
F_2 ( V_2 , L_22 ) ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
if ( ! V_42 || ! F_9 ( V_42 ) )
return;
F_10 ( & V_42 -> V_43 ) ;
if ( V_42 -> V_44 && V_42 -> V_44 -> V_45 ) {
const struct V_46 * V_46 = V_42 -> V_44 -> V_45 -> V_47 ;
F_2 ( V_2 , L_23 ,
F_11 ( & V_48 , V_46 -> V_49 ) ,
F_12 ( & V_48 , V_46 -> V_50 ) ) ;
}
F_13 ( & V_42 -> V_43 ) ;
}
void
F_14 ( struct V_1 * V_2 , V_24 V_51 ,
unsigned int V_52 , const struct V_3 * V_4 ,
const struct V_53 * V_54 ,
const struct V_53 * V_12 ,
const struct V_55 * V_56 , const char * V_57 )
{
F_2 ( V_2 , V_58 L_24 ,
'0' + V_56 -> V_59 . log . V_60 , V_57 ,
V_54 ? V_54 -> V_61 : L_25 ,
V_12 ? V_12 -> V_61 : L_25 ) ;
#if F_15 ( V_62 )
if ( V_4 -> V_63 ) {
const struct V_53 * V_64 ;
const struct V_53 * V_65 ;
V_64 = F_16 ( V_4 ) ;
if ( V_64 && V_54 != V_64 )
F_2 ( V_2 , L_26 , V_64 -> V_61 ) ;
V_65 = F_17 ( V_4 ) ;
if ( V_65 && V_12 != V_65 )
F_2 ( V_2 , L_27 , V_65 -> V_61 ) ;
}
#endif
}
void F_18 ( struct V_66 * V_66 , V_24 V_51 ,
T_2 V_67 ,
unsigned int V_52 ,
const struct V_3 * V_4 ,
const struct V_53 * V_54 ,
const struct V_53 * V_12 ,
const struct V_55 * V_56 ,
const char * V_57 )
{
switch ( V_67 ) {
case F_19 ( V_68 ) :
F_20 ( V_66 , V_69 , V_52 , V_4 , V_54 , V_12 ,
V_56 , L_28 , V_57 ) ;
break;
case F_19 ( V_70 ) :
F_20 ( V_66 , V_71 , V_52 , V_4 , V_54 , V_12 ,
V_56 , L_28 , V_57 ) ;
break;
case F_19 ( V_72 ) :
case F_19 ( V_73 ) :
F_20 ( V_66 , V_74 , V_52 , V_4 , V_54 , V_12 ,
V_56 , L_28 , V_57 ) ;
break;
}
}
static int T_3 F_21 ( void )
{
return 0 ;
}
static void T_4 F_22 ( void ) {}
