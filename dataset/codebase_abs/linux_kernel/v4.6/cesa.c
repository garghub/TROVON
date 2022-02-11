static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 ;
F_2 ( & V_8 -> V_9 ) ;
V_5 = F_3 ( & V_8 -> V_10 ) ;
V_4 = F_4 ( & V_8 -> V_10 ) ;
V_2 -> V_4 = V_4 ;
F_5 ( & V_8 -> V_9 ) ;
if ( ! V_4 )
return;
if ( V_5 )
V_5 -> V_11 ( V_5 , - V_12 ) ;
V_7 = F_6 ( V_4 -> V_13 ) ;
V_7 -> V_14 -> V_15 ( V_4 , V_2 ) ;
V_7 -> V_14 -> V_16 ( V_4 ) ;
}
static T_1 F_7 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
T_2 V_19 , V_20 ;
T_1 V_21 = V_22 ;
while ( true ) {
int V_23 ;
V_20 = F_8 ( V_2 ) ;
V_19 = F_9 ( V_2 -> V_24 + V_25 ) ;
if ( ! ( V_19 & V_20 ) )
break;
F_10 ( ~ V_19 , V_2 -> V_24 + V_26 ) ;
F_10 ( ~ V_19 , V_2 -> V_24 + V_25 ) ;
V_21 = V_27 ;
F_2 ( & V_2 -> V_9 ) ;
V_4 = V_2 -> V_4 ;
F_5 ( & V_2 -> V_9 ) ;
if ( V_4 ) {
V_7 = F_6 ( V_4 -> V_13 ) ;
V_23 = V_7 -> V_14 -> V_28 ( V_4 , V_19 & V_20 ) ;
if ( V_23 != - V_12 ) {
F_2 ( & V_2 -> V_9 ) ;
V_2 -> V_4 = NULL ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_9 ) ;
V_7 -> V_14 -> V_29 ( V_4 ) ;
F_11 () ;
V_4 -> V_11 ( V_4 , V_23 ) ;
F_12 () ;
} else {
V_7 -> V_14 -> V_16 ( V_4 ) ;
}
}
}
return V_21 ;
}
int F_13 ( struct V_3 * V_4 )
{
int V_21 ;
int V_30 ;
F_2 ( & V_8 -> V_9 ) ;
V_21 = F_14 ( & V_8 -> V_10 , V_4 ) ;
F_5 ( & V_8 -> V_9 ) ;
if ( V_21 != - V_12 )
return V_21 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_31 -> V_32 ; V_30 ++ ) {
F_2 ( & V_8 -> V_33 [ V_30 ] . V_9 ) ;
if ( ! V_8 -> V_33 [ V_30 ] . V_4 )
F_1 ( & V_8 -> V_33 [ V_30 ] ) ;
F_5 ( & V_8 -> V_33 [ V_30 ] . V_9 ) ;
}
return - V_12 ;
}
static int F_15 ( struct V_34 * V_35 )
{
int V_21 ;
int V_30 , V_36 ;
for ( V_30 = 0 ; V_30 < V_35 -> V_31 -> V_37 ; V_30 ++ ) {
V_21 = F_16 ( V_35 -> V_31 -> V_38 [ V_30 ] ) ;
if ( V_21 )
goto V_39;
}
for ( V_30 = 0 ; V_30 < V_35 -> V_31 -> V_40 ; V_30 ++ ) {
V_21 = F_17 ( V_35 -> V_31 -> V_41 [ V_30 ] ) ;
if ( V_21 )
goto V_42;
}
return 0 ;
V_42:
for ( V_36 = 0 ; V_36 < V_30 ; V_36 ++ )
F_18 ( V_35 -> V_31 -> V_41 [ V_36 ] ) ;
V_30 = V_35 -> V_31 -> V_37 ;
V_39:
for ( V_36 = 0 ; V_36 < V_30 ; V_36 ++ )
F_19 ( V_35 -> V_31 -> V_38 [ V_36 ] ) ;
return V_21 ;
}
static void F_20 ( struct V_34 * V_35 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_35 -> V_31 -> V_40 ; V_30 ++ )
F_18 ( V_35 -> V_31 -> V_41 [ V_30 ] ) ;
for ( V_30 = 0 ; V_30 < V_35 -> V_31 -> V_37 ; V_30 ++ )
F_19 ( V_35 -> V_31 -> V_38 [ V_30 ] ) ;
}
static void
F_21 ( struct V_1 * V_2 ,
const struct V_43 * V_44 )
{
void T_3 * V_45 = V_2 -> V_24 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
F_10 ( 0 , V_45 + F_22 ( V_30 ) ) ;
F_10 ( 0 , V_45 + F_23 ( V_30 ) ) ;
}
for ( V_30 = 0 ; V_30 < V_44 -> V_46 ; V_30 ++ ) {
const struct V_47 * V_48 = V_44 -> V_48 + V_30 ;
F_10 ( ( ( V_48 -> V_49 - 1 ) & 0xffff0000 ) |
( V_48 -> V_50 << 8 ) |
( V_44 -> V_51 << 4 ) | 1 ,
V_45 + F_22 ( V_30 ) ) ;
F_10 ( V_48 -> V_52 , V_45 + F_23 ( V_30 ) ) ;
}
}
static int F_24 ( struct V_34 * V_35 )
{
struct V_53 * V_54 = V_35 -> V_54 ;
struct V_55 * V_56 ;
if ( ! V_35 -> V_31 -> V_57 )
return 0 ;
V_56 = F_25 ( V_54 , sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
V_56 -> V_60 = F_26 ( L_1 , V_54 ,
sizeof( struct V_61 ) ,
16 , 0 ) ;
if ( ! V_56 -> V_60 )
return - V_59 ;
V_56 -> V_62 = F_26 ( L_2 , V_54 ,
sizeof( struct V_63 ) , 16 , 0 ) ;
if ( ! V_56 -> V_62 )
return - V_59 ;
V_56 -> V_64 = F_26 ( L_3 , V_54 ,
V_65 , 1 , 0 ) ;
if ( ! V_56 -> V_64 )
return - V_59 ;
V_56 -> V_66 = F_26 ( L_4 , V_54 , 72 , 1 , 0 ) ;
if ( ! V_56 -> V_66 )
return - V_59 ;
V_35 -> V_56 = V_56 ;
return 0 ;
}
static int F_27 ( struct V_67 * V_68 , int V_69 )
{
struct V_34 * V_35 = F_28 ( V_68 ) ;
struct V_1 * V_2 = & V_35 -> V_33 [ V_69 ] ;
const char * V_70 = L_5 ;
struct V_71 * V_23 ;
V_2 -> V_72 = F_29 ( V_35 -> V_54 -> V_73 ,
L_6 , V_69 ) ;
if ( V_2 -> V_72 ) {
V_2 -> V_74 = F_30 ( V_2 -> V_72 ,
V_35 -> V_75 ,
& V_2 -> V_76 ) ;
if ( V_2 -> V_74 )
return 0 ;
V_2 -> V_72 = NULL ;
return - V_59 ;
}
if ( V_35 -> V_31 -> V_32 > 1 ) {
if ( ! V_69 )
V_70 = L_7 ;
else
V_70 = L_8 ;
}
V_23 = F_31 ( V_68 , V_77 ,
V_70 ) ;
if ( ! V_23 || F_32 ( V_23 ) < V_35 -> V_75 )
return - V_78 ;
V_2 -> V_74 = F_33 ( V_35 -> V_54 , V_23 ) ;
if ( F_34 ( V_2 -> V_74 ) )
return F_35 ( V_2 -> V_74 ) ;
V_2 -> V_76 = F_36 ( V_35 -> V_54 ,
( V_79 ) V_23 -> V_80 ) ;
return 0 ;
}
static void F_37 ( struct V_67 * V_68 , int V_69 )
{
struct V_34 * V_35 = F_28 ( V_68 ) ;
struct V_1 * V_2 = & V_35 -> V_33 [ V_69 ] ;
if ( ! V_2 -> V_72 )
return;
F_38 ( V_2 -> V_72 , ( unsigned long ) V_2 -> V_74 ,
V_35 -> V_75 ) ;
}
static int F_39 ( struct V_67 * V_68 )
{
const struct V_81 * V_31 = & V_82 ;
const struct V_43 * V_44 ;
const struct V_83 * V_84 ;
struct V_53 * V_54 = & V_68 -> V_54 ;
struct V_34 * V_35 ;
struct V_1 * V_33 ;
struct V_71 * V_23 ;
int V_17 , V_21 , V_30 ;
T_2 V_75 ;
if ( V_8 ) {
F_40 ( & V_68 -> V_54 , L_9 ) ;
return - V_85 ;
}
if ( V_54 -> V_73 ) {
V_84 = F_41 ( V_86 , V_54 -> V_73 ) ;
if ( ! V_84 || ! V_84 -> V_87 )
return - V_88 ;
V_31 = V_84 -> V_87 ;
}
if ( ( V_31 == & V_82 || V_31 == & V_89 ) && ! V_90 )
return - V_88 ;
V_35 = F_25 ( V_54 , sizeof( * V_35 ) , V_58 ) ;
if ( ! V_35 )
return - V_59 ;
V_35 -> V_31 = V_31 ;
V_35 -> V_54 = V_54 ;
V_75 = V_91 ;
F_42 ( V_35 -> V_54 -> V_73 , L_10 ,
& V_75 ) ;
if ( V_75 < V_92 )
V_75 = V_92 ;
V_35 -> V_75 = V_75 ;
V_35 -> V_33 = F_25 ( V_54 , V_31 -> V_32 * sizeof( * V_33 ) ,
V_58 ) ;
if ( ! V_35 -> V_33 )
return - V_59 ;
F_43 ( & V_35 -> V_9 ) ;
F_44 ( & V_35 -> V_10 , 50 ) ;
V_23 = F_31 ( V_68 , V_77 , L_11 ) ;
V_35 -> V_24 = F_33 ( V_54 , V_23 ) ;
if ( F_34 ( V_35 -> V_24 ) )
return F_35 ( V_35 -> V_24 ) ;
V_21 = F_24 ( V_35 ) ;
if ( V_21 )
return V_21 ;
V_44 = F_45 () ;
F_46 ( V_68 , V_35 ) ;
for ( V_30 = 0 ; V_30 < V_31 -> V_32 ; V_30 ++ ) {
struct V_1 * V_2 = & V_35 -> V_33 [ V_30 ] ;
char V_70 [ 7 ] ;
V_2 -> V_93 = V_30 ;
F_43 ( & V_2 -> V_9 ) ;
V_21 = F_27 ( V_68 , V_30 ) ;
if ( V_21 )
goto V_94;
V_17 = F_47 ( V_68 , V_30 ) ;
if ( V_17 < 0 ) {
V_21 = V_17 ;
goto V_94;
}
snprintf ( V_70 , sizeof( V_70 ) , L_12 , V_30 ) ;
V_2 -> V_95 = F_48 ( V_54 , V_70 ) ;
if ( F_34 ( V_2 -> V_95 ) ) {
V_2 -> V_95 = F_48 ( V_54 , NULL ) ;
if ( F_34 ( V_2 -> V_95 ) )
V_2 -> V_95 = NULL ;
}
snprintf ( V_70 , sizeof( V_70 ) , L_13 , V_30 ) ;
V_2 -> V_96 = F_48 ( V_54 , V_70 ) ;
if ( F_34 ( V_2 -> V_96 ) )
V_2 -> V_96 = NULL ;
V_21 = F_49 ( V_2 -> V_95 ) ;
if ( V_21 )
goto V_94;
V_21 = F_49 ( V_2 -> V_96 ) ;
if ( V_21 )
goto V_94;
V_2 -> V_24 = V_35 -> V_24 + F_50 ( V_30 ) ;
if ( V_44 && V_35 -> V_31 -> V_57 )
F_21 ( & V_35 -> V_33 [ V_30 ] , V_44 ) ;
F_10 ( 0 , V_35 -> V_33 [ V_30 ] . V_24 + V_25 ) ;
F_10 ( V_97 ,
V_35 -> V_33 [ V_30 ] . V_24 + V_98 ) ;
F_10 ( V_2 -> V_76 & V_99 ,
V_35 -> V_33 [ V_30 ] . V_24 + V_100 ) ;
V_21 = F_51 ( V_54 , V_17 , NULL , F_7 ,
V_101 ,
F_52 ( & V_68 -> V_54 ) ,
& V_35 -> V_33 [ V_30 ] ) ;
if ( V_21 )
goto V_94;
}
V_8 = V_35 ;
V_21 = F_15 ( V_35 ) ;
if ( V_21 ) {
V_8 = NULL ;
goto V_94;
}
F_53 ( V_54 , L_14 ) ;
return 0 ;
V_94:
for ( V_30 = 0 ; V_30 < V_31 -> V_32 ; V_30 ++ ) {
F_54 ( V_35 -> V_33 [ V_30 ] . V_96 ) ;
F_54 ( V_35 -> V_33 [ V_30 ] . V_95 ) ;
F_37 ( V_68 , V_30 ) ;
}
return V_21 ;
}
static int F_55 ( struct V_67 * V_68 )
{
struct V_34 * V_35 = F_28 ( V_68 ) ;
int V_30 ;
F_20 ( V_35 ) ;
for ( V_30 = 0 ; V_30 < V_35 -> V_31 -> V_32 ; V_30 ++ ) {
F_54 ( V_35 -> V_33 [ V_30 ] . V_96 ) ;
F_54 ( V_35 -> V_33 [ V_30 ] . V_95 ) ;
F_37 ( V_68 , V_30 ) ;
}
return 0 ;
}
