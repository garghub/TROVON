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
static int F_14 ( struct V_42 * V_43 , struct V_23 * V_24 )
{
struct V_44 V_45 ;
struct V_5 * V_6 = & V_24 -> V_32 ;
strncpy ( V_45 . type , L_1 , sizeof( V_45 . type ) ) ;
strncpy ( V_45 . V_46 , V_6 -> V_46 ? : L_2 , sizeof( V_45 . V_46 ) ) ;
V_45 . V_47 = V_24 -> V_48 ;
V_45 . V_19 = V_6 -> V_19 ;
V_45 . V_34 = V_6 -> V_34 ;
if ( F_15 ( V_43 , V_49 ,
sizeof( struct V_44 ) , & V_45 ) )
goto V_50;
return 0 ;
V_50:
return - V_51 ;
}
static int F_14 ( struct V_42 * V_43 , struct V_23 * V_24 )
{
return - V_29 ;
}
static void F_16 ( struct V_52 * V_53 , struct V_23 * V_24 )
{
struct V_5 * V_6 = & V_24 -> V_32 ;
F_17 ( V_53 , L_3 ) ;
F_17 ( V_53 , L_4 , V_24 -> V_36 & V_54 ?
L_5 : L_6 ) ;
F_17 ( V_53 , L_7 , V_24 -> V_48 ) ;
F_17 ( V_53 , L_8 , V_6 -> V_34 ) ;
F_17 ( V_53 , L_9 , V_6 -> V_19 ) ;
F_17 ( V_53 , L_10 , V_6 -> V_46 ? : L_2 ) ;
}
static int F_18 ( struct V_27 * V_28 )
{
return F_19 ( & V_28 -> V_55 ) ;
}
static int F_20 ( struct V_27 * V_28 )
{
return F_21 ( & V_28 -> V_55 ) ;
}
static int F_22 ( struct V_30 * V_2 , T_2 type , T_2 V_25 )
{
struct V_5 * V_24 = & V_2 -> V_31 -> V_32 ;
struct V_16 * V_17 = & V_2 -> V_33 ;
if ( F_12 ( V_24 -> V_19 , V_24 -> V_34 ) > V_35 / 8 )
return - V_20 ;
V_17 -> V_14 = V_14 ;
V_17 -> V_38 = V_24 -> V_38 ;
V_17 -> V_39 = V_24 -> V_39 ;
if ( ! V_24 -> V_34 ) {
V_17 -> V_40 = F_18 ;
V_17 -> V_41 = F_20 ;
}
V_17 -> V_22 = F_13 ( V_2 ) ;
V_17 -> V_34 = V_24 -> V_34 ;
V_17 -> V_15 = V_24 -> V_19 ;
return 0 ;
}
static int F_23 ( struct V_42 * V_43 , struct V_23 * V_24 )
{
struct V_44 V_45 ;
struct V_5 * V_6 = & V_24 -> V_32 ;
strncpy ( V_45 . type , L_11 , sizeof( V_45 . type ) ) ;
strncpy ( V_45 . V_46 , V_6 -> V_46 , sizeof( V_45 . V_46 ) ) ;
V_45 . V_47 = V_24 -> V_48 ;
V_45 . V_19 = V_6 -> V_19 ;
V_45 . V_34 = V_6 -> V_34 ;
if ( F_15 ( V_43 , V_49 ,
sizeof( struct V_44 ) , & V_45 ) )
goto V_50;
return 0 ;
V_50:
return - V_51 ;
}
static int F_23 ( struct V_42 * V_43 , struct V_23 * V_24 )
{
return - V_29 ;
}
static void F_24 ( struct V_52 * V_53 , struct V_23 * V_24 )
{
struct V_5 * V_6 = & V_24 -> V_32 ;
F_17 ( V_53 , L_12 ) ;
F_17 ( V_53 , L_4 , V_24 -> V_36 & V_54 ?
L_5 : L_6 ) ;
F_17 ( V_53 , L_7 , V_24 -> V_48 ) ;
F_17 ( V_53 , L_8 , V_6 -> V_34 ) ;
F_17 ( V_53 , L_9 , V_6 -> V_19 ) ;
F_17 ( V_53 , L_10 , V_6 -> V_46 ) ;
}
static int F_25 ( struct V_56 * V_57 ,
const char * V_58 , T_2 type , T_2 V_25 )
{
struct V_23 * V_24 ;
int V_18 ;
type &= ~ ( V_59 | V_37 ) ;
type |= V_60 ;
V_25 |= V_59 | V_37 ;
V_24 = F_26 ( V_58 , type , V_25 ) ;
if ( F_27 ( V_24 ) )
return F_28 ( V_24 ) ;
V_18 = F_29 ( & V_57 -> V_22 , V_24 , V_57 -> V_22 . V_61 , V_25 ) ;
F_30 ( V_24 ) ;
return V_18 ;
}
struct V_62 * F_31 ( struct V_63 * V_64 ,
struct V_65 * * V_66 , T_2 type ,
T_2 V_25 )
{
const char * V_58 ;
struct V_56 * V_57 ;
struct V_67 * V_68 ;
struct V_62 * V_61 ;
struct V_23 * V_24 ;
int V_18 ;
V_68 = F_32 ( V_66 ) ;
if ( F_27 ( V_68 ) )
return F_33 ( V_68 ) ;
if ( ( V_68 -> type ^ ( V_60 | V_37 ) ) &
V_68 -> V_25 )
return F_34 ( - V_20 ) ;
V_58 = F_35 ( V_66 [ 1 ] ) ;
if ( F_27 ( V_58 ) )
return F_33 ( V_58 ) ;
V_61 = F_36 ( sizeof( * V_61 ) + sizeof( * V_57 ) , V_69 ) ;
if ( ! V_61 )
return F_34 ( - V_13 ) ;
V_57 = F_37 ( V_61 ) ;
V_25 |= F_38 ( V_68 -> type , V_68 -> V_25 ) ;
F_39 ( V_57 , V_61 ) ;
V_18 = F_25 ( V_57 , V_58 , type , V_25 ) ;
if ( V_18 )
goto V_70;
V_24 = F_40 ( V_57 ) ;
V_18 = - V_20 ;
if ( ! V_24 -> V_32 . V_34 )
goto V_71;
if ( V_68 -> V_25 & V_37 ) {
if ( strcmp ( V_64 -> V_58 , V_24 -> V_32 . V_46 ) )
goto V_71;
memcpy ( V_61 -> V_24 . V_72 , V_24 -> V_72 , V_73 ) ;
memcpy ( V_61 -> V_24 . V_74 , V_24 -> V_74 ,
V_73 ) ;
} else {
V_18 = - V_75 ;
if ( snprintf ( V_61 -> V_24 . V_72 , V_73 ,
L_13 , V_64 -> V_58 , V_24 -> V_72 ) >=
V_73 )
goto V_71;
if ( snprintf ( V_61 -> V_24 . V_74 , V_73 ,
L_13 , V_64 -> V_58 , V_24 -> V_74 ) >=
V_73 )
goto V_71;
}
V_61 -> V_24 . V_36 = V_60 | V_37 ;
V_61 -> V_24 . V_36 |= V_24 -> V_36 & V_54 ;
V_61 -> V_24 . V_76 = V_24 -> V_76 ;
V_61 -> V_24 . V_48 = V_24 -> V_48 ;
V_61 -> V_24 . V_77 = V_24 -> V_77 ;
V_61 -> V_24 . V_78 = & V_79 ;
V_61 -> V_24 . V_32 . V_34 = V_24 -> V_32 . V_34 ;
V_61 -> V_24 . V_32 . V_19 = V_24 -> V_32 . V_19 ;
V_61 -> V_24 . V_32 . V_46 = V_24 -> V_32 . V_46 ;
V_61 -> V_24 . V_32 . V_14 = V_24 -> V_32 . V_14 ;
V_61 -> V_24 . V_32 . V_21 = V_24 -> V_32 . V_21 ;
V_61 -> V_24 . V_32 . V_38 = V_24 -> V_32 . V_38 ;
V_61 -> V_24 . V_32 . V_39 = V_24 -> V_32 . V_39 ;
V_80:
return V_61 ;
V_71:
F_41 ( V_57 ) ;
V_70:
F_6 ( V_61 ) ;
V_61 = F_34 ( V_18 ) ;
goto V_80;
}
void F_42 ( struct V_62 * V_61 )
{
F_41 ( F_37 ( V_61 ) ) ;
F_6 ( V_61 ) ;
}
int F_43 ( struct V_30 * V_2 )
{
struct V_62 * V_61 = ( void * ) V_2 -> V_31 ;
struct V_1 * V_6 ;
V_6 = F_44 ( F_37 ( V_61 ) ) ;
if ( F_27 ( V_6 ) )
return F_28 ( V_6 ) ;
V_2 -> V_33 . V_22 = V_6 ;
V_2 -> V_33 . V_81 += F_45 ( V_6 ) ;
return 0 ;
}
void F_46 ( struct V_30 * V_2 )
{
F_47 ( V_2 -> V_33 . V_22 ) ;
}
static int F_48 ( struct V_23 * V_24 , T_2 type , T_2 V_25 )
{
struct V_65 * V_66 [ 3 ] ;
struct {
struct V_65 V_82 ;
struct V_67 V_83 ;
} V_84 ;
struct {
struct V_65 V_82 ;
struct V_85 V_83 ;
} V_86 ;
struct V_63 * V_64 ;
struct V_62 * V_61 ;
struct V_23 * V_87 ;
const char * V_46 ;
int V_18 ;
V_87 = F_49 ( V_24 -> V_74 ,
V_60 | V_37 ,
V_59 | V_37 ) ;
V_18 = F_28 ( V_87 ) ;
if ( F_27 ( V_87 ) )
goto V_80;
V_18 = - V_88 ;
if ( ! F_50 ( V_87 ) )
goto V_89;
V_84 . V_82 . V_90 = sizeof( V_84 ) ;
V_84 . V_82 . V_91 = V_92 ;
V_84 . V_83 . type = type | V_37 ;
V_84 . V_83 . V_25 = V_25 | V_37 ;
V_66 [ 0 ] = & V_84 . V_82 ;
V_86 . V_82 . V_90 = sizeof( V_86 ) ;
V_86 . V_82 . V_91 = V_93 ;
memcpy ( V_86 . V_83 . V_58 , V_24 -> V_74 , V_73 ) ;
V_66 [ 1 ] = & V_86 . V_82 ;
V_66 [ 2 ] = NULL ;
V_46 = V_24 -> V_32 . V_46 ;
V_64 = F_51 ( V_46 ) ;
V_18 = - V_94 ;
if ( ! V_64 )
goto V_95;
V_61 = V_64 -> V_96 ( V_66 ) ;
V_18 = F_28 ( V_61 ) ;
if ( F_27 ( V_61 ) )
goto V_97;
if ( ( V_18 = F_52 ( V_64 , V_61 ) ) ) {
V_64 -> free ( V_61 ) ;
goto V_97;
}
V_18 = - V_88 ;
V_97:
F_53 ( V_64 ) ;
V_95:
F_54 ( V_87 ) ;
V_89:
F_30 ( V_87 ) ;
V_80:
F_30 ( V_24 ) ;
return V_18 ;
}
struct V_23 * F_55 ( const char * V_58 , T_2 type , T_2 V_25 )
{
struct V_23 * V_24 ;
V_24 = F_26 ( V_58 , type , V_25 ) ;
if ( F_27 ( V_24 ) )
return V_24 ;
if ( V_24 -> V_78 == & V_79 )
return V_24 ;
if ( ! V_24 -> V_32 . V_34 )
return V_24 ;
F_30 ( V_24 ) ;
V_24 = F_26 ( V_58 , type | V_98 ,
V_25 & ~ V_98 ) ;
if ( F_27 ( V_24 ) )
return V_24 ;
if ( V_24 -> V_78 == & V_79 ) {
if ( ( V_24 -> V_36 ^ type ^ ~ V_25 ) & V_98 ) {
F_30 ( V_24 ) ;
V_24 = F_34 ( - V_94 ) ;
}
return V_24 ;
}
F_56 ( ! V_24 -> V_32 . V_34 ) ;
return F_34 ( F_48 ( V_24 , type , V_25 ) ) ;
}
int F_57 ( struct V_56 * V_57 , const char * V_58 ,
T_2 type , T_2 V_25 )
{
struct V_23 * V_24 ;
int V_18 ;
type &= ~ ( V_59 | V_37 ) ;
type |= V_60 ;
V_25 &= ~ ( V_59 | V_37 ) ;
V_25 |= V_59 ;
V_24 = F_55 ( V_58 , type , V_25 ) ;
if ( F_27 ( V_24 ) )
return F_28 ( V_24 ) ;
V_18 = F_29 ( & V_57 -> V_22 , V_24 , V_57 -> V_22 . V_61 , V_25 ) ;
F_30 ( V_24 ) ;
return V_18 ;
}
struct V_1 * F_58 ( const char * V_99 , T_2 type , T_2 V_25 )
{
struct V_30 * V_2 ;
int V_18 ;
type &= ~ ( V_59 | V_37 ) ;
type |= V_60 ;
V_25 &= ~ ( V_59 | V_37 ) ;
V_25 |= V_59 ;
for (; ; ) {
struct V_23 * V_24 ;
V_24 = F_55 ( V_99 , type , V_25 ) ;
if ( F_27 ( V_24 ) ) {
V_18 = F_28 ( V_24 ) ;
goto V_18;
}
V_2 = F_59 ( V_24 , type , V_25 ) ;
if ( ! F_27 ( V_2 ) )
return F_13 ( V_2 ) ;
F_30 ( V_24 ) ;
V_18 = F_28 ( V_2 ) ;
V_18:
if ( V_18 != - V_88 )
break;
if ( F_60 ( V_100 ) ) {
V_18 = - V_101 ;
break;
}
}
return F_34 ( V_18 ) ;
}
