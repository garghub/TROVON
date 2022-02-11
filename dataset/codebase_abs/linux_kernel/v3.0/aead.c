static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 = F_3 ( V_2 ) ;
int V_8 ;
T_1 * V_9 , * V_10 ;
unsigned long V_11 ;
V_11 = V_4 + V_7 ;
V_9 = F_4 ( V_11 , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = ( T_1 * ) F_5 ( ( unsigned long ) V_9 , V_7 + 1 ) ;
memcpy ( V_10 , V_3 , V_4 ) ;
V_8 = V_6 -> V_14 ( V_2 , V_10 , V_4 ) ;
memset ( V_10 , 0 , V_4 ) ;
F_6 ( V_9 ) ;
return V_8 ;
}
static int V_14 ( struct V_1 * V_2 , const T_1 * V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 = F_3 ( V_2 ) ;
if ( ( unsigned long ) V_3 & V_7 )
return F_1 ( V_2 , V_3 , V_4 ) ;
return V_6 -> V_14 ( V_2 , V_3 , V_4 ) ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_15 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
int V_18 ;
if ( V_15 > F_2 ( V_2 ) -> V_19 )
return - V_20 ;
if ( F_2 ( V_2 ) -> V_21 ) {
V_18 = F_2 ( V_2 ) -> V_21 ( V_17 -> V_22 , V_15 ) ;
if ( V_18 )
return V_18 ;
}
F_8 ( V_17 -> V_22 ) -> V_15 = V_15 ;
V_17 -> V_15 = V_15 ;
return 0 ;
}
static unsigned int F_9 ( struct V_23 * V_24 , T_2 type ,
T_2 V_25 )
{
return V_24 -> V_26 ;
}
static int F_10 ( struct V_27 * V_28 )
{
return - V_29 ;
}
static int F_11 ( struct V_30 * V_2 , T_2 type , T_2 V_25 )
{
struct V_5 * V_24 = & V_2 -> V_31 -> V_32 ;
struct V_16 * V_17 = & V_2 -> V_33 ;
if ( F_12 ( V_24 -> V_19 , V_24 -> V_34 ) > V_35 / 8 )
return - V_20 ;
V_17 -> V_14 = V_2 -> V_31 -> V_36 & V_37 ?
V_24 -> V_14 : V_14 ;
V_17 -> V_38 = V_24 -> V_38 ;
V_17 -> V_39 = V_24 -> V_39 ;
V_17 -> V_40 = V_24 -> V_40 ? : F_10 ;
V_17 -> V_41 = V_24 -> V_41 ? : F_10 ;
V_17 -> V_22 = F_13 ( V_2 ) ;
V_17 -> V_34 = V_24 -> V_34 ;
V_17 -> V_15 = V_24 -> V_19 ;
return 0 ;
}
static void F_14 ( struct V_42 * V_43 , struct V_23 * V_24 )
{
struct V_5 * V_6 = & V_24 -> V_32 ;
F_15 ( V_43 , L_1 ) ;
F_15 ( V_43 , L_2 , V_24 -> V_36 & V_44 ?
L_3 : L_4 ) ;
F_15 ( V_43 , L_5 , V_24 -> V_45 ) ;
F_15 ( V_43 , L_6 , V_6 -> V_34 ) ;
F_15 ( V_43 , L_7 , V_6 -> V_19 ) ;
F_15 ( V_43 , L_8 , V_6 -> V_46 ? : L_9 ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
return F_17 ( & V_28 -> V_47 ) ;
}
static int F_18 ( struct V_27 * V_28 )
{
return F_19 ( & V_28 -> V_47 ) ;
}
static int F_20 ( struct V_30 * V_2 , T_2 type , T_2 V_25 )
{
struct V_5 * V_24 = & V_2 -> V_31 -> V_32 ;
struct V_16 * V_17 = & V_2 -> V_33 ;
if ( F_12 ( V_24 -> V_19 , V_24 -> V_34 ) > V_35 / 8 )
return - V_20 ;
V_17 -> V_14 = V_14 ;
V_17 -> V_38 = V_24 -> V_38 ;
V_17 -> V_39 = V_24 -> V_39 ;
if ( ! V_24 -> V_34 ) {
V_17 -> V_40 = F_16 ;
V_17 -> V_41 = F_18 ;
}
V_17 -> V_22 = F_13 ( V_2 ) ;
V_17 -> V_34 = V_24 -> V_34 ;
V_17 -> V_15 = V_24 -> V_19 ;
return 0 ;
}
static void F_21 ( struct V_42 * V_43 , struct V_23 * V_24 )
{
struct V_5 * V_6 = & V_24 -> V_32 ;
F_15 ( V_43 , L_10 ) ;
F_15 ( V_43 , L_2 , V_24 -> V_36 & V_44 ?
L_3 : L_4 ) ;
F_15 ( V_43 , L_5 , V_24 -> V_45 ) ;
F_15 ( V_43 , L_6 , V_6 -> V_34 ) ;
F_15 ( V_43 , L_7 , V_6 -> V_19 ) ;
F_15 ( V_43 , L_8 , V_6 -> V_46 ) ;
}
static int F_22 ( struct V_48 * V_49 ,
const char * V_50 , T_2 type , T_2 V_25 )
{
struct V_23 * V_24 ;
int V_18 ;
type &= ~ ( V_51 | V_37 ) ;
type |= V_52 ;
V_25 |= V_51 | V_37 ;
V_24 = F_23 ( V_50 , type , V_25 ) ;
if ( F_24 ( V_24 ) )
return F_25 ( V_24 ) ;
V_18 = F_26 ( & V_49 -> V_22 , V_24 , V_49 -> V_22 . V_53 , V_25 ) ;
F_27 ( V_24 ) ;
return V_18 ;
}
struct V_54 * F_28 ( struct V_55 * V_56 ,
struct V_57 * * V_58 , T_2 type ,
T_2 V_25 )
{
const char * V_50 ;
struct V_48 * V_49 ;
struct V_59 * V_60 ;
struct V_54 * V_53 ;
struct V_23 * V_24 ;
int V_18 ;
V_60 = F_29 ( V_58 ) ;
V_18 = F_25 ( V_60 ) ;
if ( F_24 ( V_60 ) )
return F_30 ( V_18 ) ;
if ( ( V_60 -> type ^ ( V_52 | V_37 ) ) &
V_60 -> V_25 )
return F_30 ( - V_20 ) ;
V_50 = F_31 ( V_58 [ 1 ] ) ;
V_18 = F_25 ( V_50 ) ;
if ( F_24 ( V_50 ) )
return F_30 ( V_18 ) ;
V_53 = F_32 ( sizeof( * V_53 ) + sizeof( * V_49 ) , V_61 ) ;
if ( ! V_53 )
return F_30 ( - V_13 ) ;
V_49 = F_33 ( V_53 ) ;
V_25 |= F_34 ( V_60 -> type , V_60 -> V_25 ) ;
F_35 ( V_49 , V_53 ) ;
V_18 = F_22 ( V_49 , V_50 , type , V_25 ) ;
if ( V_18 )
goto V_62;
V_24 = F_36 ( V_49 ) ;
V_18 = - V_20 ;
if ( ! V_24 -> V_32 . V_34 )
goto V_63;
if ( V_60 -> V_25 & V_37 ) {
if ( strcmp ( V_56 -> V_50 , V_24 -> V_32 . V_46 ) )
goto V_63;
memcpy ( V_53 -> V_24 . V_64 , V_24 -> V_64 , V_65 ) ;
memcpy ( V_53 -> V_24 . V_66 , V_24 -> V_66 ,
V_65 ) ;
} else {
V_18 = - V_67 ;
if ( snprintf ( V_53 -> V_24 . V_64 , V_65 ,
L_11 , V_56 -> V_50 , V_24 -> V_64 ) >=
V_65 )
goto V_63;
if ( snprintf ( V_53 -> V_24 . V_66 , V_65 ,
L_11 , V_56 -> V_50 , V_24 -> V_66 ) >=
V_65 )
goto V_63;
}
V_53 -> V_24 . V_36 = V_52 | V_37 ;
V_53 -> V_24 . V_36 |= V_24 -> V_36 & V_44 ;
V_53 -> V_24 . V_68 = V_24 -> V_68 ;
V_53 -> V_24 . V_45 = V_24 -> V_45 ;
V_53 -> V_24 . V_69 = V_24 -> V_69 ;
V_53 -> V_24 . V_70 = & V_71 ;
V_53 -> V_24 . V_32 . V_34 = V_24 -> V_32 . V_34 ;
V_53 -> V_24 . V_32 . V_19 = V_24 -> V_32 . V_19 ;
V_53 -> V_24 . V_32 . V_46 = V_24 -> V_32 . V_46 ;
V_53 -> V_24 . V_32 . V_14 = V_24 -> V_32 . V_14 ;
V_53 -> V_24 . V_32 . V_21 = V_24 -> V_32 . V_21 ;
V_53 -> V_24 . V_32 . V_38 = V_24 -> V_32 . V_38 ;
V_53 -> V_24 . V_32 . V_39 = V_24 -> V_32 . V_39 ;
V_72:
return V_53 ;
V_63:
F_37 ( V_49 ) ;
V_62:
F_6 ( V_53 ) ;
V_53 = F_30 ( V_18 ) ;
goto V_72;
}
void F_38 ( struct V_54 * V_53 )
{
F_37 ( F_33 ( V_53 ) ) ;
F_6 ( V_53 ) ;
}
int F_39 ( struct V_30 * V_2 )
{
struct V_54 * V_53 = ( void * ) V_2 -> V_31 ;
struct V_1 * V_6 ;
V_6 = F_40 ( F_33 ( V_53 ) ) ;
if ( F_24 ( V_6 ) )
return F_25 ( V_6 ) ;
V_2 -> V_33 . V_22 = V_6 ;
V_2 -> V_33 . V_73 += F_41 ( V_6 ) ;
return 0 ;
}
void F_42 ( struct V_30 * V_2 )
{
F_43 ( V_2 -> V_33 . V_22 ) ;
}
static int F_44 ( struct V_23 * V_24 , T_2 type , T_2 V_25 )
{
struct V_57 * V_58 [ 3 ] ;
struct {
struct V_57 V_74 ;
struct V_59 V_75 ;
} V_76 ;
struct {
struct V_57 V_74 ;
struct V_77 V_75 ;
} V_78 ;
struct V_55 * V_56 ;
struct V_54 * V_53 ;
struct V_23 * V_79 ;
const char * V_46 ;
int V_18 ;
V_79 = F_45 ( V_24 -> V_66 ,
V_52 | V_37 ,
V_51 | V_37 ) ;
V_18 = F_25 ( V_79 ) ;
if ( F_24 ( V_79 ) )
goto V_72;
V_18 = - V_80 ;
if ( ! F_46 ( V_79 ) )
goto V_81;
V_76 . V_74 . V_82 = sizeof( V_76 ) ;
V_76 . V_74 . V_83 = V_84 ;
V_76 . V_75 . type = type | V_37 ;
V_76 . V_75 . V_25 = V_25 | V_37 ;
V_58 [ 0 ] = & V_76 . V_74 ;
V_78 . V_74 . V_82 = sizeof( V_78 ) ;
V_78 . V_74 . V_83 = V_85 ;
memcpy ( V_78 . V_75 . V_50 , V_24 -> V_66 , V_65 ) ;
V_58 [ 1 ] = & V_78 . V_74 ;
V_58 [ 2 ] = NULL ;
V_46 = V_24 -> V_32 . V_46 ;
V_56 = F_47 ( V_46 ) ;
V_18 = - V_86 ;
if ( ! V_56 )
goto V_87;
V_53 = V_56 -> V_88 ( V_58 ) ;
V_18 = F_25 ( V_53 ) ;
if ( F_24 ( V_53 ) )
goto V_89;
if ( ( V_18 = F_48 ( V_56 , V_53 ) ) ) {
V_56 -> free ( V_53 ) ;
goto V_89;
}
V_18 = - V_80 ;
V_89:
F_49 ( V_56 ) ;
V_87:
F_50 ( V_79 ) ;
V_81:
F_27 ( V_79 ) ;
V_72:
F_27 ( V_24 ) ;
return V_18 ;
}
static struct V_23 * F_51 ( const char * V_50 , T_2 type ,
T_2 V_25 )
{
struct V_23 * V_24 ;
V_24 = F_23 ( V_50 , type , V_25 ) ;
if ( F_24 ( V_24 ) )
return V_24 ;
if ( V_24 -> V_70 == & V_71 )
return V_24 ;
if ( ! V_24 -> V_32 . V_34 )
return V_24 ;
F_27 ( V_24 ) ;
V_24 = F_23 ( V_50 , type | V_90 ,
V_25 & ~ V_90 ) ;
if ( F_24 ( V_24 ) )
return V_24 ;
if ( V_24 -> V_70 == & V_71 ) {
if ( ( V_24 -> V_36 ^ type ^ ~ V_25 ) & V_90 ) {
F_27 ( V_24 ) ;
V_24 = F_30 ( - V_86 ) ;
}
return V_24 ;
}
F_52 ( ! V_24 -> V_32 . V_34 ) ;
return F_30 ( F_44 ( V_24 , type , V_25 ) ) ;
}
int F_53 ( struct V_48 * V_49 , const char * V_50 ,
T_2 type , T_2 V_25 )
{
struct V_23 * V_24 ;
int V_18 ;
type &= ~ ( V_51 | V_37 ) ;
type |= V_52 ;
V_25 &= ~ ( V_51 | V_37 ) ;
V_25 |= V_51 ;
V_24 = F_51 ( V_50 , type , V_25 ) ;
if ( F_24 ( V_24 ) )
return F_25 ( V_24 ) ;
V_18 = F_26 ( & V_49 -> V_22 , V_24 , V_49 -> V_22 . V_53 , V_25 ) ;
F_27 ( V_24 ) ;
return V_18 ;
}
struct V_1 * F_54 ( const char * V_91 , T_2 type , T_2 V_25 )
{
struct V_30 * V_2 ;
int V_18 ;
type &= ~ ( V_51 | V_37 ) ;
type |= V_52 ;
V_25 &= ~ ( V_51 | V_37 ) ;
V_25 |= V_51 ;
for (; ; ) {
struct V_23 * V_24 ;
V_24 = F_51 ( V_91 , type , V_25 ) ;
if ( F_24 ( V_24 ) ) {
V_18 = F_25 ( V_24 ) ;
goto V_18;
}
V_2 = F_55 ( V_24 , type , V_25 ) ;
if ( ! F_24 ( V_2 ) )
return F_13 ( V_2 ) ;
F_27 ( V_24 ) ;
V_18 = F_25 ( V_2 ) ;
V_18:
if ( V_18 != - V_80 )
break;
if ( F_56 ( V_92 ) ) {
V_18 = - V_93 ;
break;
}
}
return F_30 ( V_18 ) ;
}
