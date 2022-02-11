static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = V_4 -> V_12 ;
int V_13 ;
F_2 ( & V_8 -> V_14 ) ;
for ( V_13 = V_6 -> V_15 [ V_16 ] ;
V_13 < V_6 -> V_17 [ V_16 ] ; V_13 ++ )
if ( F_3 ( V_13 , & V_8 -> V_18 ) ) {
F_4 (intr_cb, &irq_info->cb_list[i],
list)
if ( V_10 -> V_19 )
V_10 -> V_19 ( V_12 -> V_1 ,
V_10 -> V_20 ) ;
}
F_5 ( & V_8 -> V_14 ) ;
return V_21 ;
}
static T_1 F_6 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = V_4 -> V_12 ;
T_2 V_18 ;
int V_13 ;
V_18 = V_4 -> V_22 -> V_23 ( V_4 ) ;
if ( ! V_18 )
return V_24 ;
F_2 ( & V_8 -> V_25 ) ;
for ( V_13 = V_6 -> V_15 [ V_16 ] ;
V_13 < V_6 -> V_17 [ V_16 ] ; V_13 ++ )
if ( V_18 & F_7 ( V_13 ) ) {
F_4 (intr_cb, &irq_info->cb_list[i],
list)
if ( V_10 -> V_26 )
V_10 -> V_26 ( V_12 -> V_1 ,
V_10 -> V_20 ) ;
F_8 ( V_13 , & V_8 -> V_18 ) ;
}
F_5 ( & V_8 -> V_25 ) ;
return V_27 ;
}
static T_3 F_9 ( struct V_3 * V_4 ,
int V_28 , enum V_29 type )
{
if ( type >= V_30 )
return V_31 ;
if ( V_28 >= V_4 -> V_6 -> V_17 [ type ] )
return V_31 ;
return V_4 -> V_6 -> V_15 [ type ] + V_28 ;
}
static struct V_32 * F_10 ( struct V_3 * V_4 )
{
int V_13 ;
struct V_7 * V_33 = & V_4 -> V_8 ;
for ( V_13 = 0 ; V_13 < V_33 -> V_34 ; V_13 ++ )
if ( ! V_33 -> V_35 [ V_13 ] )
return & V_33 -> V_36 [ V_13 ] ;
return NULL ;
}
static struct V_9 * F_11 ( struct V_3 * V_4 ,
T_4 V_37 , T_5 V_26 , T_5 V_19 ,
void * V_20 )
{
struct V_9 * V_10 ;
unsigned long V_38 ;
int V_39 ;
V_10 = F_12 ( sizeof( * V_10 ) , V_40 ) ;
if ( ! V_10 )
return F_13 ( - V_41 ) ;
V_10 -> V_26 = V_26 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_20 = V_20 ;
V_10 -> V_42 = F_14 ( & V_4 -> V_8 . V_43 ,
0 , 0 , V_40 ) ;
if ( V_10 -> V_42 < 0 ) {
V_39 = V_10 -> V_42 ;
goto V_44;
}
F_2 ( & V_4 -> V_8 . V_14 ) ;
F_15 ( & V_4 -> V_8 . V_25 , V_38 ) ;
F_16 ( & V_10 -> V_45 , & V_4 -> V_8 . V_46 [ V_37 ] ) ;
F_17 ( & V_4 -> V_8 . V_25 , V_38 ) ;
F_5 ( & V_4 -> V_8 . V_14 ) ;
return V_10 ;
V_44:
F_18 ( V_10 ) ;
return F_13 ( V_39 ) ;
}
static T_4 F_19 ( struct V_3 * V_4 , T_2 V_37 )
{
struct V_47 * V_48 , * V_49 ;
struct V_9 * V_10 ;
unsigned long V_38 ;
int V_13 ;
F_2 ( & V_4 -> V_8 . V_14 ) ;
F_15 ( & V_4 -> V_8 . V_25 , V_38 ) ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
F_20 (pos, tmp, &mdev->irq_info.cb_list[i]) {
V_10 = F_21 ( V_48 , struct V_9 , V_45 ) ;
if ( V_10 -> V_42 == V_37 ) {
F_22 ( V_48 ) ;
F_23 ( & V_4 -> V_8 . V_43 ,
V_10 -> V_42 ) ;
F_18 ( V_10 ) ;
F_17 (
& V_4 -> V_8 . V_25 , V_38 ) ;
F_5 ( & V_4 -> V_8 . V_14 ) ;
return V_13 ;
}
}
}
F_17 ( & V_4 -> V_8 . V_25 , V_38 ) ;
F_5 ( & V_4 -> V_8 . V_14 ) ;
return V_31 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_39 , V_13 ;
int V_50 = sizeof( * V_4 -> V_8 . V_36 ) ;
V_4 -> V_8 . V_36 = F_25 ( V_51 ,
V_50 , V_40 ) ;
if ( ! V_4 -> V_8 . V_36 ) {
V_39 = - V_41 ;
goto V_52;
}
for ( V_13 = 0 ; V_13 < V_51 ; V_13 ++ )
V_4 -> V_8 . V_36 [ V_13 ] . V_53 = V_13 ;
V_39 = F_26 ( V_12 , V_4 -> V_8 . V_36 ,
V_51 ) ;
if ( V_39 ) {
F_27 ( & V_12 -> V_2 , L_1 , V_39 ) ;
goto V_54;
}
V_4 -> V_8 . V_34 = V_51 ;
V_4 -> V_8 . V_35 = F_28 ( ( sizeof( T_2 ) *
V_4 -> V_8 . V_34 ) , V_40 ) ;
if ( ! V_4 -> V_8 . V_35 ) {
V_39 = - V_41 ;
goto V_55;
}
F_27 ( & V_4 -> V_12 -> V_2 ,
L_2 , V_4 -> V_8 . V_34 ) ;
return 0 ;
V_55:
F_29 ( V_12 ) ;
V_54:
F_18 ( V_4 -> V_8 . V_36 ) ;
V_52:
V_4 -> V_8 . V_34 = 0 ;
return V_39 ;
}
static int F_30 ( struct V_3 * V_4 )
{
int V_13 ;
V_4 -> V_8 . V_46 = F_25 ( V_31 ,
sizeof( * V_4 -> V_8 . V_46 ) ,
V_40 ) ;
if ( ! V_4 -> V_8 . V_46 )
return - V_41 ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ )
F_31 ( & V_4 -> V_8 . V_46 [ V_13 ] ) ;
F_32 ( & V_4 -> V_8 . V_43 ) ;
F_33 ( & V_4 -> V_8 . V_25 ) ;
F_33 ( & V_4 -> V_8 . V_14 ) ;
return 0 ;
}
static void F_34 ( struct V_3 * V_4 )
{
unsigned long V_38 ;
struct V_47 * V_48 , * V_49 ;
struct V_9 * V_10 ;
int V_13 ;
F_2 ( & V_4 -> V_8 . V_14 ) ;
F_15 ( & V_4 -> V_8 . V_25 , V_38 ) ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
if ( F_35 ( & V_4 -> V_8 . V_46 [ V_13 ] ) )
break;
F_20 (pos, tmp, &mdev->irq_info.cb_list[i]) {
V_10 = F_21 ( V_48 , struct V_9 , V_45 ) ;
F_22 ( V_48 ) ;
F_23 ( & V_4 -> V_8 . V_43 ,
V_10 -> V_42 ) ;
F_18 ( V_10 ) ;
}
}
F_17 ( & V_4 -> V_8 . V_25 , V_38 ) ;
F_5 ( & V_4 -> V_8 . V_14 ) ;
F_36 ( & V_4 -> V_8 . V_43 ) ;
F_18 ( V_4 -> V_8 . V_46 ) ;
}
static int F_37 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_39 ;
V_39 = F_38 ( V_12 ) ;
if ( V_39 ) {
F_27 ( & V_12 -> V_2 , L_3 , V_39 ) ;
return V_39 ;
}
V_4 -> V_8 . V_34 = 1 ;
V_4 -> V_8 . V_35 = F_28 ( ( sizeof( T_2 ) *
V_4 -> V_8 . V_34 ) , V_40 ) ;
if ( ! V_4 -> V_8 . V_35 ) {
V_39 = - V_41 ;
goto V_52;
}
V_39 = F_30 ( V_4 ) ;
if ( V_39 ) {
F_39 ( & V_12 -> V_2 , L_4 ) ;
goto V_55;
}
V_39 = F_40 ( V_12 -> V_1 , F_6 , F_1 ,
0 , L_5 , V_4 ) ;
if ( V_39 ) {
F_39 ( & V_12 -> V_2 , L_6 ) ;
goto V_56;
}
F_27 ( & V_12 -> V_2 , L_7 , V_4 -> V_8 . V_34 ) ;
return 0 ;
V_56:
F_34 ( V_4 ) ;
V_55:
F_18 ( V_4 -> V_8 . V_35 ) ;
V_52:
F_41 ( V_12 ) ;
V_4 -> V_8 . V_34 = 0 ;
return V_39 ;
}
static int F_42 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_39 ;
F_43 ( V_12 , 1 ) ;
V_39 = F_30 ( V_4 ) ;
if ( V_39 ) {
F_39 ( & V_12 -> V_2 , L_4 ) ;
goto V_57;
}
V_39 = F_40 ( V_12 -> V_1 , F_6 , F_1 ,
V_58 , L_8 , V_4 ) ;
if ( V_39 )
goto V_59;
F_27 ( & V_12 -> V_2 , L_9 ) ;
return 0 ;
V_59:
F_34 ( V_4 ) ;
V_57:
return V_39 ;
}
int F_44 ( struct V_3 * V_4 )
{
int V_60 ;
V_60 = V_4 -> V_8 . V_61 %
V_4 -> V_6 -> V_17 [ V_16 ] ;
V_4 -> V_8 . V_61 ++ ;
return V_60 ;
}
struct V_62 *
F_45 ( struct V_3 * V_4 ,
T_5 V_26 , T_5 V_19 ,
const char * V_63 , void * V_20 , int V_28 ,
enum V_29 type )
{
T_3 V_64 ;
int V_39 = 0 ;
struct V_32 * V_65 = NULL ;
unsigned long V_66 = 0 ;
T_3 V_53 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_64 = F_9 ( V_4 , V_28 , type ) ;
if ( V_64 >= V_31 ) {
F_39 ( & V_4 -> V_12 -> V_2 ,
L_10 ,
V_28 ) ;
V_39 = - V_67 ;
goto V_59;
}
if ( V_4 -> V_8 . V_34 > 1 ) {
V_65 = F_10 ( V_4 ) ;
if ( ! V_65 ) {
F_39 ( & V_4 -> V_12 -> V_2 ,
L_11 ) ;
V_39 = - V_68 ;
goto V_59;
}
V_39 = F_40 ( V_65 -> V_69 , V_26 , V_19 ,
0 , V_63 , V_20 ) ;
if ( V_39 ) {
F_27 ( & V_4 -> V_12 -> V_2 ,
L_12 , V_39 ) ;
goto V_59;
}
V_53 = V_65 -> V_53 ;
V_4 -> V_8 . V_35 [ V_53 ] |= F_7 ( V_64 ) ;
V_4 -> V_70 -> V_71 ( V_4 ,
V_53 , V_64 , true ) ;
V_66 = F_46 ( V_53 , V_64 ) ;
F_27 ( & V_4 -> V_12 -> V_2 , L_13 ,
V_65 -> V_69 , V_28 ) ;
} else {
V_10 = F_11 ( V_4 , V_64 , V_26 ,
V_19 , V_20 ) ;
if ( F_47 ( V_10 ) ) {
F_39 ( & V_4 -> V_12 -> V_2 ,
L_14 ) ;
V_39 = F_48 ( V_10 ) ;
goto V_59;
}
V_53 = 0 ;
if ( F_49 ( V_12 ) ) {
V_4 -> V_8 . V_35 [ V_53 ] |= ( 1 << V_64 ) ;
V_4 -> V_70 -> V_71 ( V_4 ,
V_53 , V_64 , true ) ;
}
V_66 = F_46 ( V_53 , V_10 -> V_42 ) ;
F_27 ( & V_4 -> V_12 -> V_2 , L_15 ,
V_10 -> V_42 , V_28 ) ;
}
return (struct V_62 * ) V_66 ;
V_59:
return F_13 ( V_39 ) ;
}
void F_50 ( struct V_3 * V_4 ,
struct V_62 * V_66 , void * V_20 )
{
T_2 V_64 ;
T_2 V_53 ;
T_4 V_72 ;
unsigned int V_1 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_53 = F_51 ( ( unsigned long ) V_66 ) ;
V_64 = F_52 ( ( unsigned long ) V_66 ) ;
if ( V_4 -> V_8 . V_34 > 1 ) {
if ( V_53 >= V_4 -> V_8 . V_34 ) {
F_53 ( & V_4 -> V_12 -> V_2 ,
L_16 ,
V_53 , V_4 -> V_8 . V_34 ) ;
return;
}
V_1 = V_4 -> V_8 . V_36 [ V_53 ] . V_69 ;
F_54 ( V_1 , V_20 ) ;
V_4 -> V_8 . V_35 [ V_53 ] &= ~ ( F_7 ( V_64 ) ) ;
V_4 -> V_70 -> V_71 ( V_4 ,
V_53 , V_64 , false ) ;
F_27 ( & V_4 -> V_12 -> V_2 , L_17 , V_1 ) ;
} else {
V_1 = V_12 -> V_1 ;
V_72 = F_19 ( V_4 , V_64 ) ;
if ( V_72 >= V_31 ) {
F_53 ( & V_4 -> V_12 -> V_2 , L_18 ) ;
return;
}
if ( F_49 ( V_12 ) ) {
V_4 -> V_8 . V_35 [ V_53 ] &= ~ ( F_7 ( V_72 ) ) ;
V_4 -> V_70 -> V_71 ( V_4 ,
V_53 , V_72 , false ) ;
}
F_27 ( & V_4 -> V_12 -> V_2 , L_19 ,
V_64 , V_72 ) ;
}
}
int F_55 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_39 ;
V_39 = F_24 ( V_4 , V_12 ) ;
if ( ! V_39 )
goto V_73;
V_39 = F_37 ( V_4 , V_12 ) ;
if ( ! V_39 )
goto V_73;
V_39 = F_42 ( V_4 , V_12 ) ;
if ( V_39 ) {
F_39 ( & V_4 -> V_12 -> V_2 , L_20 ) ;
return V_39 ;
}
V_73:
V_4 -> V_70 -> V_74 ( V_4 ) ;
return 0 ;
}
void F_56 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_13 ;
V_4 -> V_70 -> V_75 ( V_4 ) ;
if ( V_4 -> V_8 . V_34 > 1 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_8 . V_34 ; V_13 ++ ) {
if ( V_4 -> V_8 . V_35 [ V_13 ] )
F_53 ( & V_12 -> V_2 , L_21 ,
V_4 -> V_8 . V_36 [ V_13 ] . V_69 ) ;
}
F_18 ( V_4 -> V_8 . V_35 ) ;
F_18 ( V_4 -> V_8 . V_36 ) ;
F_29 ( V_12 ) ;
} else {
if ( F_49 ( V_12 ) ) {
F_54 ( V_12 -> V_1 , V_4 ) ;
F_18 ( V_4 -> V_8 . V_35 ) ;
F_41 ( V_12 ) ;
} else {
F_54 ( V_12 -> V_1 , V_4 ) ;
}
F_34 ( V_4 ) ;
}
}
void F_57 ( struct V_3 * V_4 )
{
int V_53 , V_64 ;
struct V_11 * V_12 = V_4 -> V_12 ;
if ( ! F_49 ( V_12 ) )
return;
for ( V_53 = 0 ; V_53 < V_4 -> V_8 . V_34 ; V_53 ++ ) {
for ( V_64 = 0 ; V_64 < V_31 ; V_64 ++ ) {
if ( V_4 -> V_8 . V_35 [ V_53 ] & F_7 ( V_64 ) )
V_4 -> V_70 -> V_71 ( V_4 ,
V_53 , V_64 , true ) ;
}
}
}
