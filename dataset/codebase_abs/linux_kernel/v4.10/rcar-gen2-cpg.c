static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
unsigned int V_7 ;
V_7 = ( F_3 ( V_5 -> V_8 ) & V_9 ) >> V_10 ;
V_6 = 32 - V_7 ;
return F_4 ( ( V_11 ) V_3 * V_6 , 32 ) ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long * V_3 )
{
unsigned long V_13 = * V_3 ;
unsigned int V_6 ;
if ( ! V_13 )
V_13 = 1 ;
V_6 = F_4 ( ( V_11 ) V_12 * 32 , V_13 ) ;
V_6 = F_6 ( V_6 , 1U , 32U ) ;
return * V_3 / 32 * V_6 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
T_1 V_7 , V_14 ;
unsigned int V_15 ;
V_6 = F_4 ( ( V_11 ) V_12 * 32 , V_3 ) ;
V_6 = F_6 ( V_6 , 1U , 32U ) ;
if ( F_3 ( V_5 -> V_16 ) & V_17 )
return - V_18 ;
V_7 = F_3 ( V_5 -> V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= ( 32 - V_6 ) << V_10 ;
F_8 ( V_7 , V_5 -> V_8 ) ;
V_14 = F_3 ( V_5 -> V_16 ) ;
V_14 |= V_17 ;
F_8 ( V_14 , V_5 -> V_16 ) ;
for ( V_15 = 1000 ; V_15 ; V_15 -- ) {
if ( ! ( F_3 ( V_5 -> V_16 ) & V_17 ) )
return 0 ;
F_9 () ;
}
return - V_19 ;
}
static struct V_20 * T_2 F_10 ( const char * V_21 ,
const char * V_22 ,
void T_3 * V_23 )
{
struct V_24 V_25 ;
struct V_4 * V_5 ;
struct V_20 * V_20 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return F_12 ( - V_27 ) ;
V_25 . V_21 = V_21 ;
V_25 . V_28 = & V_29 ;
V_25 . V_30 = 0 ;
V_25 . V_31 = & V_22 ;
V_25 . V_32 = 1 ;
V_5 -> V_8 = V_23 + V_33 ;
V_5 -> V_16 = V_23 + V_34 ;
V_5 -> V_2 . V_25 = & V_25 ;
V_20 = F_13 ( NULL , & V_5 -> V_2 ) ;
if ( F_14 ( V_20 ) )
F_15 ( V_5 ) ;
return V_20 ;
}
static struct V_20 * T_2 F_16 ( const char * V_21 ,
const char * V_22 ,
void T_3 * V_23 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_20 * V_20 ;
V_36 = F_11 ( sizeof( * V_36 ) , V_26 ) ;
if ( ! V_36 )
return F_12 ( - V_27 ) ;
V_36 -> V_6 = 1 ;
V_36 -> div = 6 ;
V_38 = F_11 ( sizeof( * V_38 ) , V_26 ) ;
if ( ! V_38 ) {
F_15 ( V_36 ) ;
return F_12 ( - V_27 ) ;
}
V_38 -> V_8 = V_23 + V_39 ;
V_38 -> V_40 = 8 ;
V_38 -> V_30 = V_41 ;
V_38 -> V_42 = & V_43 ;
V_20 = F_17 ( NULL , V_21 , & V_22 , 1 , NULL , NULL ,
& V_36 -> V_2 , & V_44 ,
& V_38 -> V_2 , & V_45 , 0 ) ;
if ( F_14 ( V_20 ) ) {
F_15 ( V_38 ) ;
F_15 ( V_36 ) ;
}
return V_20 ;
}
static struct V_20 * T_2 F_18 ( const char * V_21 ,
const char * V_22 ,
void T_3 * V_23 )
{
struct V_46 * div ;
struct V_37 * V_38 ;
struct V_20 * V_20 ;
div = F_11 ( sizeof( * div ) , V_26 ) ;
if ( ! div )
return F_12 ( - V_27 ) ;
div -> V_8 = V_23 + V_47 ;
div -> V_48 = 4 ;
div -> V_49 = V_50 ;
div -> V_42 = & V_43 ;
V_38 = F_11 ( sizeof( * V_38 ) , V_26 ) ;
if ( ! V_38 ) {
F_15 ( div ) ;
return F_12 ( - V_27 ) ;
}
V_38 -> V_8 = V_23 + V_47 ;
V_38 -> V_40 = 8 ;
V_38 -> V_30 = V_41 ;
V_38 -> V_42 = & V_43 ;
V_20 = F_17 ( NULL , V_21 , & V_22 , 1 , NULL , NULL ,
& div -> V_2 , & V_51 ,
& V_38 -> V_2 , & V_45 , 0 ) ;
if ( F_14 ( V_20 ) ) {
F_15 ( V_38 ) ;
F_15 ( div ) ;
}
return V_20 ;
}
struct V_20 * T_2 F_19 ( struct V_52 * V_53 ,
const struct V_54 * V_55 ,
const struct V_56 * V_57 ,
struct V_20 * * V_58 ,
void T_3 * V_23 )
{
const struct V_59 * V_49 = NULL ;
const struct V_20 * V_60 ;
const char * V_22 ;
unsigned int V_6 = 1 ;
unsigned int div = 1 ;
unsigned int V_61 ;
V_60 = V_58 [ V_55 -> V_60 ] ;
if ( F_14 ( V_60 ) )
return F_20 ( V_60 ) ;
V_22 = F_21 ( V_60 ) ;
switch ( V_55 -> type ) {
case V_62 :
div = V_63 -> V_64 ;
break;
case V_65 :
V_6 = V_63 -> V_66 ;
div = V_67 ;
if ( ! V_6 ) {
T_1 V_68 = F_3 ( V_23 + V_69 ) ;
V_6 = ( ( ( V_68 & V_70 ) >>
V_71 ) + 1 ) * 2 ;
}
break;
case V_72 :
V_6 = V_63 -> V_73 / 2 ;
break;
case V_74 :
V_6 = V_63 -> V_75 ;
break;
case V_76 :
return F_10 ( V_55 -> V_21 , V_22 , V_23 ) ;
case V_77 :
div = V_78 & F_22 ( 18 ) ? 36 : 24 ;
break;
case V_79 :
return F_18 ( V_55 -> V_21 , V_22 , V_23 ) ;
case V_80 :
V_49 = V_81 ;
V_61 = 8 ;
break;
case V_82 :
V_49 = V_83 ;
V_61 = 4 ;
break;
case V_84 :
V_49 = V_83 ;
V_61 = 0 ;
break;
case V_85 :
div = ( V_78 & ( F_22 ( 3 ) | F_22 ( 2 ) | F_22 ( 1 ) ) ) == F_22 ( 2 ) ?
8 : 10 ;
break;
case V_86 :
return F_16 ( V_55 -> V_21 , V_22 , V_23 ) ;
default:
return F_12 ( - V_87 ) ;
}
if ( ! V_49 )
return F_23 ( NULL , V_55 -> V_21 , V_22 ,
0 , V_6 , div ) ;
else
return F_24 ( NULL , V_55 -> V_21 ,
V_22 , 0 ,
V_23 + V_88 , V_61 , 4 ,
0 , V_49 , & V_43 ) ;
}
int T_2 F_25 ( const struct V_89 * V_90 ,
unsigned int V_91 , T_1 V_92 )
{
V_63 = V_90 ;
V_67 = V_91 ;
V_78 = V_92 ;
F_26 ( & V_43 ) ;
return 0 ;
}
