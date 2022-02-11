static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_2 ( V_4 -> V_13 -> V_14 ,
struct V_11 , V_2 ) ;
int V_15 ;
F_3 ( & V_8 -> V_16 ) ;
for ( V_15 = V_6 -> V_17 [ V_18 ] ;
V_15 < V_6 -> V_19 [ V_18 ] ; V_15 ++ )
if ( F_4 ( V_15 , & V_8 -> V_20 ) ) {
F_5 (intr_cb, &irq_info->cb_list[i],
list)
if ( V_10 -> V_21 )
V_10 -> V_21 ( V_12 -> V_1 ,
V_10 -> V_22 ) ;
}
F_6 ( & V_8 -> V_16 ) ;
return V_23 ;
}
static T_1 F_7 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_2 ( V_4 -> V_13 -> V_14 ,
struct V_11 , V_2 ) ;
T_2 V_20 ;
int V_15 ;
V_20 = V_4 -> V_24 -> V_25 ( V_4 ) ;
if ( ! V_20 )
return V_26 ;
F_3 ( & V_8 -> V_27 ) ;
for ( V_15 = V_6 -> V_17 [ V_18 ] ;
V_15 < V_6 -> V_19 [ V_18 ] ; V_15 ++ )
if ( V_20 & F_8 ( V_15 ) ) {
F_5 (intr_cb, &irq_info->cb_list[i],
list)
if ( V_10 -> V_28 )
V_10 -> V_28 ( V_12 -> V_1 ,
V_10 -> V_22 ) ;
F_9 ( V_15 , & V_8 -> V_20 ) ;
}
F_6 ( & V_8 -> V_27 ) ;
return V_29 ;
}
static T_3 F_10 ( struct V_3 * V_4 ,
int V_30 , enum V_31 type )
{
if ( type >= V_32 )
return V_33 ;
if ( V_30 >= V_4 -> V_6 -> V_19 [ type ] )
return V_33 ;
return V_4 -> V_6 -> V_17 [ type ] + V_30 ;
}
static struct V_34 * F_11 ( struct V_3 * V_4 )
{
int V_15 ;
struct V_7 * V_35 = & V_4 -> V_8 ;
for ( V_15 = 0 ; V_15 < V_35 -> V_36 ; V_15 ++ )
if ( ! V_35 -> V_37 [ V_15 ] )
return & V_35 -> V_38 [ V_15 ] ;
return NULL ;
}
static struct V_9 * F_12 ( struct V_3 * V_4 ,
T_4 V_39 , T_5 V_28 , T_5 V_21 ,
void * V_22 )
{
struct V_9 * V_10 ;
unsigned long V_40 ;
int V_41 ;
V_10 = F_13 ( sizeof( * V_10 ) , V_42 ) ;
if ( ! V_10 )
return F_14 ( - V_43 ) ;
V_10 -> V_28 = V_28 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_22 = V_22 ;
V_10 -> V_44 = F_15 ( & V_4 -> V_8 . V_45 ,
0 , 0 , V_42 ) ;
if ( V_10 -> V_44 < 0 ) {
V_41 = V_10 -> V_44 ;
goto V_46;
}
F_3 ( & V_4 -> V_8 . V_16 ) ;
F_16 ( & V_4 -> V_8 . V_27 , V_40 ) ;
F_17 ( & V_10 -> V_47 , & V_4 -> V_8 . V_48 [ V_39 ] ) ;
F_18 ( & V_4 -> V_8 . V_27 , V_40 ) ;
F_6 ( & V_4 -> V_8 . V_16 ) ;
return V_10 ;
V_46:
F_19 ( V_10 ) ;
return F_14 ( V_41 ) ;
}
static T_4 F_20 ( struct V_3 * V_4 , T_2 V_39 )
{
struct V_49 * V_50 , * V_51 ;
struct V_9 * V_10 ;
unsigned long V_40 ;
int V_15 ;
F_3 ( & V_4 -> V_8 . V_16 ) ;
F_16 ( & V_4 -> V_8 . V_27 , V_40 ) ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ ) {
F_21 (pos, tmp, &mdev->irq_info.cb_list[i]) {
V_10 = F_22 ( V_50 , struct V_9 , V_47 ) ;
if ( V_10 -> V_44 == V_39 ) {
F_23 ( V_50 ) ;
F_24 ( & V_4 -> V_8 . V_45 ,
V_10 -> V_44 ) ;
F_19 ( V_10 ) ;
F_18 (
& V_4 -> V_8 . V_27 , V_40 ) ;
F_6 ( & V_4 -> V_8 . V_16 ) ;
return V_15 ;
}
}
}
F_18 ( & V_4 -> V_8 . V_27 , V_40 ) ;
F_6 ( & V_4 -> V_8 . V_16 ) ;
return V_33 ;
}
static int F_25 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_41 , V_15 ;
int V_52 = sizeof( * V_4 -> V_8 . V_38 ) ;
V_4 -> V_8 . V_38 = F_26 ( V_53 ,
V_52 , V_42 ) ;
if ( ! V_4 -> V_8 . V_38 ) {
V_41 = - V_43 ;
goto V_54;
}
for ( V_15 = 0 ; V_15 < V_53 ; V_15 ++ )
V_4 -> V_8 . V_38 [ V_15 ] . V_55 = V_15 ;
V_41 = F_27 ( V_12 , V_4 -> V_8 . V_38 ,
V_53 ) ;
if ( V_41 ) {
F_28 ( & V_12 -> V_2 , L_1 , V_41 ) ;
goto V_56;
}
V_4 -> V_8 . V_36 = V_53 ;
V_4 -> V_8 . V_37 = F_29 ( ( sizeof( T_2 ) *
V_4 -> V_8 . V_36 ) , V_42 ) ;
if ( ! V_4 -> V_8 . V_37 ) {
V_41 = - V_43 ;
goto V_57;
}
F_28 ( V_4 -> V_13 -> V_14 ,
L_2 , V_4 -> V_8 . V_36 ) ;
return 0 ;
V_57:
F_30 ( V_12 ) ;
V_56:
F_19 ( V_4 -> V_8 . V_38 ) ;
V_54:
V_4 -> V_8 . V_36 = 0 ;
return V_41 ;
}
static int F_31 ( struct V_3 * V_4 )
{
int V_15 ;
V_4 -> V_8 . V_48 = F_26 ( V_33 ,
sizeof( * V_4 -> V_8 . V_48 ) ,
V_42 ) ;
if ( ! V_4 -> V_8 . V_48 )
return - V_43 ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ )
F_32 ( & V_4 -> V_8 . V_48 [ V_15 ] ) ;
F_33 ( & V_4 -> V_8 . V_45 ) ;
F_34 ( & V_4 -> V_8 . V_27 ) ;
F_34 ( & V_4 -> V_8 . V_16 ) ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 )
{
unsigned long V_40 ;
struct V_49 * V_50 , * V_51 ;
struct V_9 * V_10 ;
int V_15 ;
F_3 ( & V_4 -> V_8 . V_16 ) ;
F_16 ( & V_4 -> V_8 . V_27 , V_40 ) ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ ) {
if ( F_36 ( & V_4 -> V_8 . V_48 [ V_15 ] ) )
break;
F_21 (pos, tmp, &mdev->irq_info.cb_list[i]) {
V_10 = F_22 ( V_50 , struct V_9 , V_47 ) ;
F_23 ( V_50 ) ;
F_24 ( & V_4 -> V_8 . V_45 ,
V_10 -> V_44 ) ;
F_19 ( V_10 ) ;
}
}
F_18 ( & V_4 -> V_8 . V_27 , V_40 ) ;
F_6 ( & V_4 -> V_8 . V_16 ) ;
F_37 ( & V_4 -> V_8 . V_45 ) ;
F_19 ( V_4 -> V_8 . V_48 ) ;
}
static int F_38 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_41 ;
V_41 = F_39 ( V_12 ) ;
if ( V_41 ) {
F_28 ( & V_12 -> V_2 , L_3 , V_41 ) ;
return V_41 ;
}
V_4 -> V_8 . V_36 = 1 ;
V_4 -> V_8 . V_37 = F_29 ( ( sizeof( T_2 ) *
V_4 -> V_8 . V_36 ) , V_42 ) ;
if ( ! V_4 -> V_8 . V_37 ) {
V_41 = - V_43 ;
goto V_54;
}
V_41 = F_31 ( V_4 ) ;
if ( V_41 ) {
F_40 ( & V_12 -> V_2 , L_4 ) ;
goto V_57;
}
V_41 = F_41 ( V_12 -> V_1 , F_7 , F_1 ,
0 , L_5 , V_4 ) ;
if ( V_41 ) {
F_40 ( & V_12 -> V_2 , L_6 ) ;
goto V_58;
}
F_28 ( & V_12 -> V_2 , L_7 , V_4 -> V_8 . V_36 ) ;
return 0 ;
V_58:
F_35 ( V_4 ) ;
V_57:
F_19 ( V_4 -> V_8 . V_37 ) ;
V_54:
F_42 ( V_12 ) ;
V_4 -> V_8 . V_36 = 0 ;
return V_41 ;
}
static int F_43 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_41 ;
F_44 ( V_12 , 1 ) ;
V_41 = F_31 ( V_4 ) ;
if ( V_41 ) {
F_40 ( & V_12 -> V_2 , L_4 ) ;
goto V_59;
}
V_41 = F_41 ( V_12 -> V_1 , F_7 , F_1 ,
V_60 , L_8 , V_4 ) ;
if ( V_41 )
goto V_61;
F_28 ( & V_12 -> V_2 , L_9 ) ;
return 0 ;
V_61:
F_35 ( V_4 ) ;
V_59:
return V_41 ;
}
int F_45 ( struct V_3 * V_4 )
{
int V_62 ;
V_62 = V_4 -> V_8 . V_63 %
V_4 -> V_6 -> V_19 [ V_18 ] ;
V_4 -> V_8 . V_63 ++ ;
return V_62 ;
}
struct V_64 *
F_46 ( struct V_3 * V_4 ,
T_5 V_28 , T_5 V_21 ,
const char * V_65 , void * V_22 , int V_30 ,
enum V_31 type )
{
T_3 V_66 ;
int V_41 = 0 ;
struct V_34 * V_67 = NULL ;
unsigned long V_68 = 0 ;
T_3 V_55 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_2 ( V_4 -> V_13 -> V_14 ,
struct V_11 , V_2 ) ;
V_66 = F_10 ( V_4 , V_30 , type ) ;
if ( V_66 >= V_33 ) {
F_40 ( V_4 -> V_13 -> V_14 ,
L_10 ,
V_30 ) ;
V_41 = - V_69 ;
goto V_61;
}
if ( V_4 -> V_8 . V_36 > 1 ) {
V_67 = F_11 ( V_4 ) ;
if ( ! V_67 ) {
F_40 ( V_4 -> V_13 -> V_14 ,
L_11 ) ;
V_41 = - V_70 ;
goto V_61;
}
V_41 = F_41 ( V_67 -> V_71 , V_28 , V_21 ,
0 , V_65 , V_22 ) ;
if ( V_41 ) {
F_28 ( V_4 -> V_13 -> V_14 ,
L_12 , V_41 ) ;
goto V_61;
}
V_55 = V_67 -> V_55 ;
V_4 -> V_8 . V_37 [ V_55 ] |= F_8 ( V_66 ) ;
V_4 -> V_72 -> V_73 ( V_4 ,
V_55 , V_66 , true ) ;
V_68 = F_47 ( V_55 , V_66 ) ;
F_28 ( V_4 -> V_13 -> V_14 , L_13 ,
V_67 -> V_71 , V_30 ) ;
} else {
V_10 = F_12 ( V_4 , V_66 , V_28 ,
V_21 , V_22 ) ;
if ( F_48 ( V_10 ) ) {
F_40 ( V_4 -> V_13 -> V_14 ,
L_14 ) ;
V_41 = F_49 ( V_10 ) ;
goto V_61;
}
V_55 = 0 ;
if ( F_50 ( V_12 ) ) {
V_4 -> V_8 . V_37 [ V_55 ] |= ( 1 << V_66 ) ;
V_4 -> V_72 -> V_73 ( V_4 ,
V_55 , V_66 , true ) ;
}
V_68 = F_47 ( V_55 , V_10 -> V_44 ) ;
F_28 ( V_4 -> V_13 -> V_14 , L_15 ,
V_10 -> V_44 , V_30 ) ;
}
return (struct V_64 * ) V_68 ;
V_61:
return F_14 ( V_41 ) ;
}
void F_51 ( struct V_3 * V_4 ,
struct V_64 * V_68 , void * V_22 )
{
T_2 V_66 ;
T_2 V_55 ;
T_4 V_74 ;
unsigned int V_1 ;
struct V_11 * V_12 = F_2 ( V_4 -> V_13 -> V_14 ,
struct V_11 , V_2 ) ;
V_55 = F_52 ( ( unsigned long ) V_68 ) ;
V_66 = F_53 ( ( unsigned long ) V_68 ) ;
if ( V_4 -> V_8 . V_36 > 1 ) {
if ( V_55 >= V_4 -> V_8 . V_36 ) {
F_54 ( V_4 -> V_13 -> V_14 ,
L_16 ,
V_55 , V_4 -> V_8 . V_36 ) ;
return;
}
V_1 = V_4 -> V_8 . V_38 [ V_55 ] . V_71 ;
F_55 ( V_1 , V_22 ) ;
V_4 -> V_8 . V_37 [ V_55 ] &= ~ ( F_8 ( V_66 ) ) ;
V_4 -> V_72 -> V_73 ( V_4 ,
V_55 , V_66 , false ) ;
F_28 ( V_4 -> V_13 -> V_14 , L_17 , V_1 ) ;
} else {
V_1 = V_12 -> V_1 ;
V_74 = F_20 ( V_4 , V_66 ) ;
if ( V_74 >= V_33 ) {
F_54 ( V_4 -> V_13 -> V_14 , L_18 ) ;
return;
}
if ( F_50 ( V_12 ) ) {
V_4 -> V_8 . V_37 [ V_55 ] &= ~ ( F_8 ( V_74 ) ) ;
V_4 -> V_72 -> V_73 ( V_4 ,
V_55 , V_74 , false ) ;
}
F_28 ( V_4 -> V_13 -> V_14 , L_19 ,
V_66 , V_74 ) ;
}
}
int F_56 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_41 ;
V_41 = F_25 ( V_4 , V_12 ) ;
if ( ! V_41 )
goto V_75;
V_41 = F_38 ( V_4 , V_12 ) ;
if ( ! V_41 )
goto V_75;
V_41 = F_43 ( V_4 , V_12 ) ;
if ( V_41 ) {
F_40 ( V_4 -> V_13 -> V_14 , L_20 ) ;
return V_41 ;
}
V_75:
V_4 -> V_72 -> V_76 ( V_4 ) ;
return 0 ;
}
void F_57 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_15 ;
V_4 -> V_72 -> V_77 ( V_4 ) ;
if ( V_4 -> V_8 . V_36 > 1 ) {
for ( V_15 = 0 ; V_15 < V_4 -> V_8 . V_36 ; V_15 ++ ) {
if ( V_4 -> V_8 . V_37 [ V_15 ] )
F_54 ( & V_12 -> V_2 , L_21 ,
V_4 -> V_8 . V_38 [ V_15 ] . V_71 ) ;
}
F_19 ( V_4 -> V_8 . V_37 ) ;
F_19 ( V_4 -> V_8 . V_38 ) ;
F_30 ( V_12 ) ;
} else {
if ( F_50 ( V_12 ) ) {
F_55 ( V_12 -> V_1 , V_4 ) ;
F_19 ( V_4 -> V_8 . V_37 ) ;
F_42 ( V_12 ) ;
} else {
F_55 ( V_12 -> V_1 , V_4 ) ;
}
F_35 ( V_4 ) ;
}
}
void F_58 ( struct V_3 * V_4 )
{
int V_55 , V_66 ;
struct V_11 * V_12 = F_2 ( V_4 -> V_13 -> V_14 ,
struct V_11 , V_2 ) ;
if ( ! F_50 ( V_12 ) )
return;
for ( V_55 = 0 ; V_55 < V_4 -> V_8 . V_36 ; V_55 ++ ) {
for ( V_66 = 0 ; V_66 < V_33 ; V_66 ++ ) {
if ( V_4 -> V_8 . V_37 [ V_55 ] & F_8 ( V_66 ) )
V_4 -> V_72 -> V_73 ( V_4 ,
V_55 , V_66 , true ) ;
}
}
}
