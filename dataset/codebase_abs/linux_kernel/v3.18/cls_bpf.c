static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
int V_12 ;
F_3 (prog, &head->plist, link) {
int V_13 = F_4 ( V_11 -> V_14 , V_2 ) ;
if ( V_13 == 0 )
continue;
* V_6 = V_11 -> V_6 ;
if ( V_13 != - 1 )
V_6 -> V_15 = V_13 ;
V_12 = F_5 ( V_2 , & V_11 -> V_16 , V_6 ) ;
if ( V_12 < 0 )
continue;
return V_12 ;
}
return - 1 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_17 ) ;
if ( V_8 == NULL )
return - V_18 ;
F_8 ( & V_8 -> V_19 ) ;
F_9 ( V_4 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
F_11 ( & V_11 -> V_16 ) ;
F_12 ( V_11 -> V_14 ) ;
F_13 ( V_11 -> V_20 ) ;
F_13 ( V_11 ) ;
}
static void F_14 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_15 ( V_22 , struct V_10 , V_22 ) ;
F_10 ( V_11 -> V_4 , V_11 ) ;
}
static int F_16 ( struct V_3 * V_4 , unsigned long V_23 )
{
struct V_7 * V_8 = F_17 ( V_4 -> V_9 ) ;
struct V_10 * V_11 , * V_24 = (struct V_10 * ) V_23 ;
F_18 (prog, &head->plist, link) {
if ( V_11 == V_24 ) {
F_19 ( & V_11 -> V_25 ) ;
F_20 ( V_4 , & V_11 -> V_6 ) ;
F_21 ( & V_11 -> V_22 , F_14 ) ;
return 0 ;
}
}
return - V_26 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_17 ( V_4 -> V_9 ) ;
struct V_10 * V_11 , * V_27 ;
F_23 (prog, tmp, &head->plist, link) {
F_19 ( & V_11 -> V_25 ) ;
F_20 ( V_4 , & V_11 -> V_6 ) ;
F_21 ( & V_11 -> V_22 , F_14 ) ;
}
F_24 ( V_4 -> V_9 , NULL ) ;
F_25 ( V_8 , V_22 ) ;
}
static unsigned long F_26 ( struct V_3 * V_4 , T_1 V_28 )
{
struct V_7 * V_8 = F_17 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
unsigned long V_12 = 0UL ;
if ( V_8 == NULL )
return 0UL ;
F_3 (prog, &head->plist, link) {
if ( V_11 -> V_28 == V_28 ) {
V_12 = ( unsigned long ) V_11 ;
break;
}
}
return V_12 ;
}
static void F_27 ( struct V_3 * V_4 , unsigned long V_29 )
{
}
static int F_28 ( struct V_30 * V_30 , struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_31 , struct V_32 * * V_33 ,
struct V_32 * V_34 , bool V_35 )
{
struct V_36 * V_20 ;
struct V_37 V_16 ;
struct V_38 V_27 ;
struct V_39 * V_40 ;
T_2 V_41 , V_42 ;
T_1 V_15 ;
int V_12 ;
if ( ! V_33 [ V_43 ] || ! V_33 [ V_44 ] || ! V_33 [ V_45 ] )
return - V_46 ;
F_29 ( & V_16 , V_47 , V_48 ) ;
V_12 = F_30 ( V_30 , V_4 , V_33 , V_34 , & V_16 , V_35 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 = F_31 ( V_33 [ V_45 ] ) ;
V_42 = F_32 ( V_33 [ V_43 ] ) ;
if ( V_42 > V_49 || V_42 == 0 ) {
V_12 = - V_46 ;
goto V_50;
}
V_41 = V_42 * sizeof( * V_20 ) ;
V_20 = F_7 ( V_41 , V_17 ) ;
if ( V_20 == NULL ) {
V_12 = - V_51 ;
goto V_50;
}
memcpy ( V_20 , F_33 ( V_33 [ V_44 ] ) , V_41 ) ;
V_27 . V_52 = V_42 ;
V_27 . V_14 = V_20 ;
V_12 = F_34 ( & V_40 , & V_27 ) ;
if ( V_12 )
goto V_53;
V_11 -> V_42 = V_42 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_14 = V_40 ;
V_11 -> V_6 . V_15 = V_15 ;
F_35 ( V_4 , & V_11 -> V_6 , V_31 ) ;
F_36 ( V_4 , & V_11 -> V_16 , & V_16 ) ;
return 0 ;
V_53:
F_13 ( V_20 ) ;
V_50:
F_11 ( & V_16 ) ;
return V_12 ;
}
static T_1 F_37 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
unsigned int V_54 = 0x80000000 ;
do {
if ( ++ V_8 -> V_55 == 0x7FFFFFFF )
V_8 -> V_55 = 1 ;
} while ( -- V_54 > 0 && F_26 ( V_4 , V_8 -> V_55 ) );
if ( V_54 == 0 )
F_38 ( L_1 ) ;
return V_54 ;
}
static int F_39 ( struct V_30 * V_30 , struct V_1 * V_56 ,
struct V_3 * V_4 , unsigned long V_31 ,
T_1 V_28 , struct V_32 * * V_57 ,
unsigned long * V_23 , bool V_35 )
{
struct V_7 * V_8 = F_17 ( V_4 -> V_9 ) ;
struct V_10 * V_58 = (struct V_10 * ) * V_23 ;
struct V_32 * V_33 [ V_59 + 1 ] ;
struct V_10 * V_11 ;
int V_12 ;
if ( V_57 [ V_60 ] == NULL )
return - V_46 ;
V_12 = F_40 ( V_33 , V_59 , V_57 [ V_60 ] , V_61 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_17 ) ;
if ( ! V_11 )
return - V_18 ;
F_29 ( & V_11 -> V_16 , V_47 , V_48 ) ;
if ( V_58 ) {
if ( V_28 && V_58 -> V_28 != V_28 ) {
V_12 = - V_46 ;
goto V_50;
}
}
if ( V_28 == 0 )
V_11 -> V_28 = F_37 ( V_4 , V_8 ) ;
else
V_11 -> V_28 = V_28 ;
if ( V_11 -> V_28 == 0 ) {
V_12 = - V_46 ;
goto V_50;
}
V_12 = F_28 ( V_30 , V_4 , V_11 , V_31 , V_33 , V_57 [ V_62 ] , V_35 ) ;
if ( V_12 < 0 )
goto V_50;
if ( V_58 ) {
F_41 ( & V_11 -> V_25 , & V_58 -> V_25 ) ;
F_20 ( V_4 , & V_58 -> V_6 ) ;
F_21 ( & V_58 -> V_22 , F_14 ) ;
} else {
F_42 ( & V_11 -> V_25 , & V_8 -> V_19 ) ;
}
* V_23 = ( unsigned long ) V_11 ;
return 0 ;
V_50:
F_13 ( V_11 ) ;
return V_12 ;
}
static int F_43 ( struct V_30 * V_30 , struct V_3 * V_4 , unsigned long V_63 ,
struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_10 * V_11 = (struct V_10 * ) V_63 ;
struct V_32 * V_66 , * V_67 ;
if ( V_11 == NULL )
return V_2 -> V_52 ;
V_65 -> V_68 = V_11 -> V_28 ;
V_66 = F_44 ( V_2 , V_60 ) ;
if ( V_66 == NULL )
goto V_69;
if ( F_45 ( V_2 , V_45 , V_11 -> V_6 . V_15 ) )
goto V_69;
if ( F_46 ( V_2 , V_43 , V_11 -> V_42 ) )
goto V_69;
V_67 = F_47 ( V_2 , V_44 , V_11 -> V_42 *
sizeof( struct V_36 ) ) ;
if ( V_67 == NULL )
goto V_69;
memcpy ( F_33 ( V_67 ) , V_11 -> V_20 , F_48 ( V_67 ) ) ;
if ( F_49 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_69;
F_50 ( V_2 , V_66 ) ;
if ( F_51 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_69;
return V_2 -> V_52 ;
V_69:
F_52 ( V_2 , V_66 ) ;
return - 1 ;
}
static void F_53 ( struct V_3 * V_4 , struct V_70 * V_23 )
{
struct V_7 * V_8 = F_17 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
F_3 (prog, &head->plist, link) {
if ( V_23 -> V_71 < V_23 -> V_72 )
goto V_72;
if ( V_23 -> V_73 ( V_4 , ( unsigned long ) V_11 , V_23 ) < 0 ) {
V_23 -> V_74 = 1 ;
break;
}
V_72:
V_23 -> V_71 ++ ;
}
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_75 ) ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_75 ) ;
}
