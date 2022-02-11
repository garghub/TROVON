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
struct V_10 * V_11 = (struct V_10 * ) V_23 ;
F_17 ( & V_11 -> V_24 ) ;
F_18 ( V_4 , & V_11 -> V_6 ) ;
F_19 ( & V_11 -> V_22 , F_14 ) ;
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_10 * V_11 , * V_25 ;
F_22 (prog, tmp, &head->plist, link) {
F_17 ( & V_11 -> V_24 ) ;
F_18 ( V_4 , & V_11 -> V_6 ) ;
F_19 ( & V_11 -> V_22 , F_14 ) ;
}
F_23 ( V_4 -> V_9 , NULL ) ;
F_24 ( V_8 , V_22 ) ;
}
static unsigned long F_25 ( struct V_3 * V_4 , T_1 V_26 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
unsigned long V_12 = 0UL ;
if ( V_8 == NULL )
return 0UL ;
F_26 (prog, &head->plist, link) {
if ( V_11 -> V_26 == V_26 ) {
V_12 = ( unsigned long ) V_11 ;
break;
}
}
return V_12 ;
}
static int F_27 ( struct V_27 * V_27 , struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_28 , struct V_29 * * V_30 ,
struct V_29 * V_31 , bool V_32 )
{
struct V_33 * V_20 ;
struct V_34 V_16 ;
struct V_35 V_25 ;
struct V_36 * V_37 ;
T_2 V_38 , V_39 ;
T_1 V_15 ;
int V_12 ;
if ( ! V_30 [ V_40 ] || ! V_30 [ V_41 ] || ! V_30 [ V_42 ] )
return - V_43 ;
F_28 ( & V_16 , V_44 , V_45 ) ;
V_12 = F_29 ( V_27 , V_4 , V_30 , V_31 , & V_16 , V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 = F_30 ( V_30 [ V_42 ] ) ;
V_39 = F_31 ( V_30 [ V_40 ] ) ;
if ( V_39 > V_46 || V_39 == 0 ) {
V_12 = - V_43 ;
goto V_47;
}
V_38 = V_39 * sizeof( * V_20 ) ;
if ( V_38 != F_32 ( V_30 [ V_41 ] ) ) {
V_12 = - V_43 ;
goto V_47;
}
V_20 = F_7 ( V_38 , V_17 ) ;
if ( V_20 == NULL ) {
V_12 = - V_48 ;
goto V_47;
}
memcpy ( V_20 , F_33 ( V_30 [ V_41 ] ) , V_38 ) ;
V_25 . V_49 = V_39 ;
V_25 . V_14 = V_20 ;
V_12 = F_34 ( & V_37 , & V_25 ) ;
if ( V_12 )
goto V_50;
V_11 -> V_39 = V_39 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_14 = V_37 ;
V_11 -> V_6 . V_15 = V_15 ;
F_35 ( V_4 , & V_11 -> V_6 , V_28 ) ;
F_36 ( V_4 , & V_11 -> V_16 , & V_16 ) ;
return 0 ;
V_50:
F_13 ( V_20 ) ;
V_47:
F_11 ( & V_16 ) ;
return V_12 ;
}
static T_1 F_37 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
unsigned int V_51 = 0x80000000 ;
T_1 V_26 ;
do {
if ( ++ V_8 -> V_52 == 0x7FFFFFFF )
V_8 -> V_52 = 1 ;
} while ( -- V_51 > 0 && F_25 ( V_4 , V_8 -> V_52 ) );
if ( F_38 ( V_51 == 0 ) ) {
F_39 ( L_1 ) ;
V_26 = 0 ;
} else {
V_26 = V_8 -> V_52 ;
}
return V_26 ;
}
static int F_40 ( struct V_27 * V_27 , struct V_1 * V_53 ,
struct V_3 * V_4 , unsigned long V_28 ,
T_1 V_26 , struct V_29 * * V_54 ,
unsigned long * V_23 , bool V_32 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_10 * V_55 = (struct V_10 * ) * V_23 ;
struct V_29 * V_30 [ V_56 + 1 ] ;
struct V_10 * V_11 ;
int V_12 ;
if ( V_54 [ V_57 ] == NULL )
return - V_43 ;
V_12 = F_41 ( V_30 , V_56 , V_54 [ V_57 ] , V_58 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_17 ) ;
if ( ! V_11 )
return - V_18 ;
F_28 ( & V_11 -> V_16 , V_44 , V_45 ) ;
if ( V_55 ) {
if ( V_26 && V_55 -> V_26 != V_26 ) {
V_12 = - V_43 ;
goto V_47;
}
}
if ( V_26 == 0 )
V_11 -> V_26 = F_37 ( V_4 , V_8 ) ;
else
V_11 -> V_26 = V_26 ;
if ( V_11 -> V_26 == 0 ) {
V_12 = - V_43 ;
goto V_47;
}
V_12 = F_27 ( V_27 , V_4 , V_11 , V_28 , V_30 , V_54 [ V_59 ] , V_32 ) ;
if ( V_12 < 0 )
goto V_47;
if ( V_55 ) {
F_42 ( & V_11 -> V_24 , & V_55 -> V_24 ) ;
F_18 ( V_4 , & V_55 -> V_6 ) ;
F_19 ( & V_55 -> V_22 , F_14 ) ;
} else {
F_43 ( & V_11 -> V_24 , & V_8 -> V_19 ) ;
}
* V_23 = ( unsigned long ) V_11 ;
return 0 ;
V_47:
F_13 ( V_11 ) ;
return V_12 ;
}
static int F_44 ( struct V_27 * V_27 , struct V_3 * V_4 , unsigned long V_60 ,
struct V_1 * V_2 , struct V_61 * V_62 )
{
struct V_10 * V_11 = (struct V_10 * ) V_60 ;
struct V_29 * V_63 , * V_64 ;
if ( V_11 == NULL )
return V_2 -> V_49 ;
V_62 -> V_65 = V_11 -> V_26 ;
V_63 = F_45 ( V_2 , V_57 ) ;
if ( V_63 == NULL )
goto V_66;
if ( F_46 ( V_2 , V_42 , V_11 -> V_6 . V_15 ) )
goto V_66;
if ( F_47 ( V_2 , V_40 , V_11 -> V_39 ) )
goto V_66;
V_64 = F_48 ( V_2 , V_41 , V_11 -> V_39 *
sizeof( struct V_33 ) ) ;
if ( V_64 == NULL )
goto V_66;
memcpy ( F_33 ( V_64 ) , V_11 -> V_20 , F_32 ( V_64 ) ) ;
if ( F_49 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_66;
F_50 ( V_2 , V_63 ) ;
if ( F_51 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_66;
return V_2 -> V_49 ;
V_66:
F_52 ( V_2 , V_63 ) ;
return - 1 ;
}
static void F_53 ( struct V_3 * V_4 , struct V_67 * V_23 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
F_26 (prog, &head->plist, link) {
if ( V_23 -> V_68 < V_23 -> V_69 )
goto V_69;
if ( V_23 -> V_70 ( V_4 , ( unsigned long ) V_11 , V_23 ) < 0 ) {
V_23 -> V_71 = 1 ;
break;
}
V_69:
V_23 -> V_68 ++ ;
}
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_72 ) ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_72 ) ;
}
