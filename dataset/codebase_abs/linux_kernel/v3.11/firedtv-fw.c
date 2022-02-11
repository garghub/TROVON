static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_1 ( V_3 -> V_4 -> V_5 ) ;
}
static int F_2 ( struct V_2 * V_3 , T_1 V_6 , void * V_7 , T_2 V_8 ,
int V_9 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_10 , V_11 = V_4 -> V_11 ;
F_3 () ;
V_10 = F_4 ( V_4 -> V_12 , V_9 , V_4 -> V_13 ,
V_11 , V_4 -> V_14 , V_6 , V_7 , V_8 ) ;
return V_10 != V_15 ? - V_16 : 0 ;
}
int F_5 ( struct V_2 * V_3 , T_1 V_6 , void * V_7 )
{
return F_2 ( V_3 , V_6 , V_7 , 8 , V_17 ) ;
}
int F_6 ( struct V_2 * V_3 , T_1 V_6 , void * V_7 )
{
return F_2 ( V_3 , V_6 , V_7 , 4 , V_18 ) ;
}
int F_7 ( struct V_2 * V_3 , T_1 V_6 , void * V_7 , T_2 V_8 )
{
return F_2 ( V_3 , V_6 , V_7 , V_8 , V_19 ) ;
}
static int F_8 ( struct V_20 * V_21 , int V_22 )
{
struct V_23 V_24 ;
V_24 . V_25 = V_26 ;
V_24 . V_27 = ! ( ++ V_21 -> V_28 & ( V_29 - 1 ) ) ;
V_24 . V_30 = 0 ;
V_24 . V_31 = V_32 ;
return F_9 ( V_21 -> V_33 , & V_24 , & V_21 -> V_34 ,
V_22 * V_26 ) ;
}
static void F_10 ( struct V_35 * V_33 , T_3 V_36 ,
T_2 V_31 , void * V_37 , void * V_7 )
{
struct V_2 * V_3 = V_7 ;
struct V_20 * V_21 = V_3 -> V_38 ;
T_4 * V_39 , * V_40 ;
int V_41 , V_42 , V_43 = V_21 -> V_44 ;
char * V_24 , * V_45 ;
for ( V_39 = V_37 , V_40 = V_39 + V_31 / 4 ; V_39 < V_40 ; V_39 ++ ) {
V_41 = F_11 ( V_39 ) >> 16 ;
if ( F_12 ( V_41 > V_26 ) ) {
F_13 ( V_3 -> V_4 , L_1 , V_41 ) ;
V_41 = V_26 ;
}
V_24 = V_21 -> V_46 [ V_43 / V_47 ]
+ ( V_43 % V_47 ) * V_26 ;
V_45 = V_24 + V_41 ;
for ( V_24 += V_48 + V_49 ; V_24 < V_45 ;
V_24 += V_50 )
F_14 ( & V_3 -> V_51 , V_24 , 1 ) ;
V_42 = F_8 ( V_21 , V_43 ) ;
if ( F_12 ( V_42 ) )
F_13 ( V_3 -> V_4 , L_2 ) ;
V_43 = ( V_43 + 1 ) & ( V_52 - 1 ) ;
}
F_15 ( V_21 -> V_33 ) ;
V_21 -> V_44 = V_43 ;
}
int F_16 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_43 , V_42 ;
V_21 = F_17 ( sizeof( * V_21 ) , V_53 ) ;
if ( ! V_21 )
return - V_54 ;
V_21 -> V_33 = F_18 ( V_4 -> V_12 ,
V_55 , V_3 -> V_56 ,
V_4 -> V_14 , V_32 , F_10 , V_3 ) ;
if ( F_19 ( V_21 -> V_33 ) ) {
V_42 = F_20 ( V_21 -> V_33 ) ;
goto V_57;
}
V_42 = F_21 ( & V_21 -> V_34 , V_4 -> V_12 ,
V_58 , V_59 ) ;
if ( V_42 )
goto V_60;
V_21 -> V_28 = 0 ;
V_21 -> V_44 = 0 ;
for ( V_43 = 0 ; V_43 < V_58 ; V_43 ++ )
V_21 -> V_46 [ V_43 ] = F_22 ( V_21 -> V_34 . V_46 [ V_43 ] ) ;
for ( V_43 = 0 ; V_43 < V_52 ; V_43 ++ ) {
V_42 = F_8 ( V_21 , V_43 ) ;
if ( V_42 )
goto V_61;
}
V_42 = F_23 ( V_21 -> V_33 , - 1 , 0 ,
V_62 ) ;
if ( V_42 )
goto V_61;
V_3 -> V_38 = V_21 ;
return 0 ;
V_61:
F_24 ( & V_21 -> V_34 , V_4 -> V_12 ) ;
V_60:
F_25 ( V_21 -> V_33 ) ;
V_57:
F_26 ( V_21 ) ;
return V_42 ;
}
void F_27 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_38 ;
F_28 ( V_21 -> V_33 ) ;
F_24 ( & V_21 -> V_34 , F_1 ( V_3 ) -> V_12 ) ;
F_25 ( V_21 -> V_33 ) ;
F_26 ( V_21 ) ;
}
static void F_29 ( struct V_63 * V_12 , struct V_64 * V_65 ,
int V_9 , int V_66 , int V_67 , int V_11 ,
unsigned long long V_68 , void * V_69 , T_2 V_41 ,
void * V_70 )
{
struct V_2 * V_71 , * V_3 = NULL ;
struct V_1 * V_4 ;
unsigned long V_72 ;
int V_73 ;
if ( V_41 < 2 || ( ( ( V_74 * ) V_69 ) [ 0 ] & 0xf0 ) != 0 )
return;
V_73 = ( ( V_74 * ) V_69 ) [ 1 ] & 0x7 ;
F_30 ( & V_75 , V_72 ) ;
F_31 (f, &node_list, list) {
V_4 = F_1 ( V_71 ) ;
if ( V_4 -> V_11 != V_11 )
continue;
F_3 () ;
if ( V_4 -> V_12 == V_12 &&
V_4 -> V_13 == V_67 &&
( V_71 -> V_76 == V_73 || ( V_71 -> V_76 == 0 && V_73 == 0x7 ) ) ) {
V_3 = V_71 ;
break;
}
}
F_32 ( & V_75 , V_72 ) ;
if ( V_3 )
F_33 ( V_3 , V_69 , V_41 ) ;
}
static int F_34 ( struct V_77 * V_78 , const struct V_79 * V_80 )
{
struct V_2 * V_3 ;
char V_81 [ V_82 ] ;
int V_83 , V_43 , V_42 ;
V_3 = F_35 ( sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_36 ( & V_78 -> V_4 , V_3 ) ;
V_3 -> V_4 = & V_78 -> V_4 ;
V_3 -> V_56 = - 1 ;
V_3 -> V_84 = 0xff ;
V_3 -> V_85 = 0xff ;
F_37 ( & V_3 -> V_86 ) ;
F_38 ( & V_3 -> V_87 ) ;
F_37 ( & V_3 -> V_88 ) ;
F_39 ( & V_3 -> V_89 , V_90 ) ;
V_83 = F_40 ( V_78 -> V_91 , V_92 ,
V_81 , sizeof( V_81 ) ) ;
for ( V_43 = F_41 ( V_93 ) ; -- V_43 ; )
if ( strlen ( V_93 [ V_43 ] ) <= V_83 &&
strncmp ( V_81 , V_93 [ V_43 ] , V_83 ) == 0 )
break;
V_3 -> type = V_43 ;
V_42 = F_42 ( V_3 , & V_78 -> V_4 ) ;
if ( V_42 )
goto V_57;
F_43 ( & V_75 ) ;
F_44 ( & V_3 -> V_94 , & V_95 ) ;
F_45 ( & V_75 ) ;
V_42 = F_46 ( V_3 ) ;
if ( V_42 )
goto V_61;
V_42 = F_47 ( V_3 , V_93 [ V_3 -> type ] ) ;
if ( V_42 )
goto V_61;
F_48 ( V_3 ) ;
return 0 ;
V_61:
F_43 ( & V_75 ) ;
F_49 ( & V_3 -> V_94 ) ;
F_45 ( & V_75 ) ;
F_50 ( V_3 ) ;
V_57:
F_26 ( V_3 ) ;
return V_42 ;
}
static void F_51 ( struct V_77 * V_78 )
{
struct V_2 * V_3 = F_52 ( & V_78 -> V_4 ) ;
F_53 ( V_3 ) ;
F_43 ( & V_75 ) ;
F_49 ( & V_3 -> V_94 ) ;
F_45 ( & V_75 ) ;
F_50 ( V_3 ) ;
F_26 ( V_3 ) ;
}
static void F_54 ( struct V_77 * V_78 )
{
struct V_2 * V_3 = F_52 ( & V_78 -> V_4 ) ;
if ( V_3 -> V_56 >= 0 )
F_55 ( V_3 , V_3 -> V_76 ,
V_3 -> V_56 ) ;
}
static int T_5 F_56 ( void )
{
int V_96 ;
V_96 = F_57 ( & V_97 , & V_98 ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 = F_58 ( & V_99 . V_100 ) ;
if ( V_96 < 0 )
F_59 ( & V_97 ) ;
return V_96 ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_99 . V_100 ) ;
F_59 ( & V_97 ) ;
}
