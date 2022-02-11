static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ,
struct V_6 , V_10 ) ;
F_3 ( & V_2 -> V_11 . V_12 ) ;
F_4 (intr_cb, &mdev->irq_info.cb_list[idx], list)
if ( V_5 -> V_13 )
V_5 -> V_13 ( V_7 -> V_14 , V_5 -> V_15 ) ;
F_5 ( & V_2 -> V_11 . V_12 ) ;
}
static T_1 F_6 ( int V_14 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
struct V_16 * V_17 = V_2 -> V_18 ;
T_2 V_19 ;
int V_20 ;
V_19 = V_2 -> V_21 -> V_22 ( V_2 ) ;
if ( ! V_19 )
return V_23 ;
for ( V_20 = V_17 -> V_24 [ V_25 ] ;
V_20 < V_17 -> V_26 [ V_25 ] ; V_20 ++ )
if ( V_19 & F_7 ( V_20 ) )
F_1 ( V_2 , V_20 ) ;
return V_27 ;
}
static T_3 F_8 ( struct V_1 * V_2 ,
int V_28 , enum V_29 type )
{
if ( type >= V_30 )
return V_31 ;
if ( V_28 >= V_2 -> V_18 -> V_26 [ type ] )
return V_31 ;
return V_2 -> V_18 -> V_24 [ type ] + V_28 ;
}
static struct V_32 * F_9 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_33 * V_17 = & V_2 -> V_11 ;
for ( V_20 = 0 ; V_20 < V_17 -> V_34 ; V_20 ++ )
if ( ! V_17 -> V_35 [ V_20 ] )
return & V_17 -> V_36 [ V_20 ] ;
return NULL ;
}
static struct V_4 * F_10 ( struct V_1 * V_2 ,
T_4 V_3 , T_1 (* V_13) ( int V_14 , void * V_10 ) ,
void * V_15 )
{
struct V_4 * V_5 ;
unsigned long V_37 ;
int V_38 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return F_12 ( - V_40 ) ;
V_5 -> V_13 = V_13 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_41 = F_13 ( & V_2 -> V_11 . V_42 ,
0 , 0 , V_39 ) ;
if ( V_5 -> V_41 < 0 ) {
V_38 = V_5 -> V_41 ;
goto V_43;
}
F_14 ( & V_2 -> V_11 . V_12 , V_37 ) ;
F_15 ( & V_5 -> V_44 , & V_2 -> V_11 . V_45 [ V_3 ] ) ;
F_16 ( & V_2 -> V_11 . V_12 , V_37 ) ;
return V_5 ;
V_43:
F_17 ( V_5 ) ;
return F_12 ( V_38 ) ;
}
static T_4 F_18 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_46 * V_47 , * V_48 ;
struct V_4 * V_5 ;
unsigned long V_37 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) {
F_14 ( & V_2 -> V_11 . V_12 , V_37 ) ;
F_19 (pos, tmp, &mdev->irq_info.cb_list[i]) {
V_5 = F_20 ( V_47 , struct V_4 , V_44 ) ;
if ( V_5 -> V_41 == V_3 ) {
F_21 ( V_47 ) ;
F_22 ( & V_2 -> V_11 . V_42 ,
V_5 -> V_41 ) ;
F_17 ( V_5 ) ;
F_16 (
& V_2 -> V_11 . V_12 , V_37 ) ;
return V_20 ;
}
}
F_16 ( & V_2 -> V_11 . V_12 , V_37 ) ;
}
return V_31 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_38 , V_20 ;
int V_49 = sizeof( * V_2 -> V_11 . V_36 ) ;
V_2 -> V_11 . V_36 = F_24 ( V_50 ,
V_49 , V_39 ) ;
if ( ! V_2 -> V_11 . V_36 ) {
V_38 = - V_40 ;
goto V_51;
}
for ( V_20 = 0 ; V_20 < V_50 ; V_20 ++ )
V_2 -> V_11 . V_36 [ V_20 ] . V_52 = V_20 ;
V_38 = F_25 ( V_7 , V_2 -> V_11 . V_36 ,
V_50 ) ;
if ( V_38 ) {
F_26 ( & V_7 -> V_10 , L_1 , V_38 ) ;
goto V_53;
}
V_2 -> V_11 . V_34 = V_50 ;
V_2 -> V_11 . V_35 = F_27 ( ( sizeof( T_2 ) *
V_2 -> V_11 . V_34 ) , V_39 ) ;
if ( ! V_2 -> V_11 . V_35 ) {
V_38 = - V_40 ;
goto V_54;
}
F_26 ( V_2 -> V_8 -> V_9 ,
L_2 , V_2 -> V_11 . V_34 ) ;
return 0 ;
V_54:
F_28 ( V_7 ) ;
V_53:
F_17 ( V_2 -> V_11 . V_36 ) ;
V_51:
V_2 -> V_11 . V_34 = 0 ;
return V_38 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_20 ;
V_2 -> V_11 . V_45 = F_24 ( V_31 ,
sizeof( * V_2 -> V_11 . V_45 ) ,
V_39 ) ;
if ( ! V_2 -> V_11 . V_45 )
return - V_40 ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ )
F_30 ( & V_2 -> V_11 . V_45 [ V_20 ] ) ;
F_31 ( & V_2 -> V_11 . V_42 ) ;
F_32 ( & V_2 -> V_11 . V_12 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned long V_37 ;
struct V_46 * V_47 , * V_48 ;
struct V_4 * V_5 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) {
F_14 ( & V_2 -> V_11 . V_12 , V_37 ) ;
if ( F_34 ( & V_2 -> V_11 . V_45 [ V_20 ] ) ) {
F_16 ( & V_2 -> V_11 . V_12 ,
V_37 ) ;
break;
}
F_19 (pos, tmp, &mdev->irq_info.cb_list[i]) {
V_5 = F_20 ( V_47 , struct V_4 , V_44 ) ;
F_21 ( V_47 ) ;
F_22 ( & V_2 -> V_11 . V_42 ,
V_5 -> V_41 ) ;
F_17 ( V_5 ) ;
}
F_16 ( & V_2 -> V_11 . V_12 , V_37 ) ;
}
F_35 ( & V_2 -> V_11 . V_42 ) ;
F_17 ( V_2 -> V_11 . V_45 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_38 ;
V_38 = F_37 ( V_7 ) ;
if ( V_38 ) {
F_26 ( & V_7 -> V_10 , L_3 , V_38 ) ;
return V_38 ;
}
V_2 -> V_11 . V_34 = 1 ;
V_2 -> V_11 . V_35 = F_27 ( ( sizeof( T_2 ) *
V_2 -> V_11 . V_34 ) , V_39 ) ;
if ( ! V_2 -> V_11 . V_35 ) {
V_38 = - V_40 ;
goto V_51;
}
V_38 = F_29 ( V_2 ) ;
if ( V_38 ) {
F_38 ( & V_7 -> V_10 , L_4 ) ;
goto V_54;
}
V_38 = F_39 ( V_7 -> V_14 , F_6 , 0 , L_5 , V_2 ) ;
if ( V_38 ) {
F_38 ( & V_7 -> V_10 , L_6 ) ;
goto V_55;
}
F_26 ( & V_7 -> V_10 , L_7 , V_2 -> V_11 . V_34 ) ;
return 0 ;
V_55:
F_33 ( V_2 ) ;
V_54:
F_17 ( V_2 -> V_11 . V_35 ) ;
V_51:
F_40 ( V_7 ) ;
V_2 -> V_11 . V_34 = 0 ;
return V_38 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_38 ;
F_42 ( V_7 ) ;
F_43 ( V_7 , 1 ) ;
V_38 = F_29 ( V_2 ) ;
if ( V_38 ) {
F_38 ( & V_7 -> V_10 , L_4 ) ;
goto V_56;
}
V_38 = F_39 ( V_7 -> V_14 , F_6 ,
V_57 , L_8 , V_2 ) ;
if ( V_38 )
goto V_58;
F_26 ( & V_7 -> V_10 , L_9 ) ;
return 0 ;
V_58:
F_33 ( V_2 ) ;
V_56:
return V_38 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = V_2 -> V_11 . V_60 %
V_2 -> V_18 -> V_26 [ V_25 ] ;
V_2 -> V_11 . V_60 ++ ;
return V_59 ;
}
struct V_61 * F_45 ( struct V_1 * V_2 ,
T_1 (* V_13)( int V_14 , void * V_10 ) ,
const char * V_62 , void * V_15 , int V_28 ,
enum V_29 type )
{
T_3 V_63 ;
int V_38 = 0 ;
struct V_32 * V_64 = NULL ;
unsigned long V_65 = 0 ;
T_3 V_52 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ,
struct V_6 , V_10 ) ;
V_63 = F_8 ( V_2 , V_28 , type ) ;
if ( V_63 >= V_31 ) {
F_38 ( V_2 -> V_8 -> V_9 ,
L_10 ,
V_28 ) ;
V_38 = - V_66 ;
goto V_58;
}
if ( V_2 -> V_11 . V_34 > 1 ) {
V_64 = F_9 ( V_2 ) ;
if ( ! V_64 ) {
F_38 ( V_2 -> V_8 -> V_9 ,
L_11 ) ;
V_38 = - V_67 ;
goto V_58;
}
V_38 = F_39 ( V_64 -> V_68 , V_13 , 0 , V_62 , V_15 ) ;
if ( V_38 ) {
F_26 ( V_2 -> V_8 -> V_9 ,
L_12 , V_38 ) ;
goto V_58;
}
V_52 = V_64 -> V_52 ;
V_2 -> V_11 . V_35 [ V_52 ] |= F_7 ( V_63 ) ;
V_2 -> V_69 -> V_70 ( V_2 ,
V_52 , V_63 , true ) ;
V_65 = F_46 ( V_52 , V_63 ) ;
F_26 ( V_2 -> V_8 -> V_9 , L_13 ,
V_64 -> V_68 , V_28 ) ;
} else {
V_5 = F_10 ( V_2 ,
V_63 , V_13 , V_15 ) ;
if ( F_47 ( V_5 ) ) {
F_38 ( V_2 -> V_8 -> V_9 ,
L_14 ) ;
V_38 = F_48 ( V_5 ) ;
goto V_58;
}
V_52 = 0 ;
if ( F_49 ( V_7 ) ) {
V_2 -> V_11 . V_35 [ V_52 ] |= ( 1 << V_63 ) ;
V_2 -> V_69 -> V_70 ( V_2 ,
V_52 , V_63 , true ) ;
}
V_65 = F_46 ( V_52 , V_5 -> V_41 ) ;
F_26 ( V_2 -> V_8 -> V_9 , L_15 ,
V_5 -> V_41 , V_28 ) ;
}
return (struct V_61 * ) V_65 ;
V_58:
return F_12 ( V_38 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_61 * V_65 , void * V_15 )
{
T_2 V_63 ;
T_2 V_52 ;
T_4 V_71 ;
unsigned int V_14 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ,
struct V_6 , V_10 ) ;
V_52 = F_51 ( ( unsigned long ) V_65 ) ;
V_63 = F_52 ( ( unsigned long ) V_65 ) ;
if ( V_2 -> V_11 . V_34 > 1 ) {
if ( V_52 >= V_2 -> V_11 . V_34 ) {
F_53 ( V_2 -> V_8 -> V_9 ,
L_16 ,
V_52 , V_2 -> V_11 . V_34 ) ;
return;
}
V_14 = V_2 -> V_11 . V_36 [ V_52 ] . V_68 ;
F_54 ( V_14 , V_15 ) ;
V_2 -> V_11 . V_35 [ V_52 ] &= ~ ( F_7 ( V_63 ) ) ;
V_2 -> V_69 -> V_70 ( V_2 ,
V_52 , V_63 , false ) ;
F_26 ( V_2 -> V_8 -> V_9 , L_17 , V_14 ) ;
} else {
V_14 = V_7 -> V_14 ;
V_71 = F_18 ( V_2 , V_63 ) ;
if ( V_71 >= V_31 ) {
F_53 ( V_2 -> V_8 -> V_9 , L_18 ) ;
return;
}
if ( F_49 ( V_7 ) ) {
V_2 -> V_11 . V_35 [ V_52 ] &= ~ ( F_7 ( V_71 ) ) ;
V_2 -> V_69 -> V_70 ( V_2 ,
V_52 , V_71 , false ) ;
}
F_26 ( V_2 -> V_8 -> V_9 , L_19 ,
V_63 , V_71 ) ;
}
}
int F_55 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_38 ;
V_38 = F_23 ( V_2 , V_7 ) ;
if ( ! V_38 )
goto V_72;
V_38 = F_36 ( V_2 , V_7 ) ;
if ( ! V_38 )
goto V_72;
V_38 = F_41 ( V_2 , V_7 ) ;
if ( V_38 ) {
F_38 ( V_2 -> V_8 -> V_9 , L_20 ) ;
return V_38 ;
}
V_72:
V_2 -> V_69 -> V_73 ( V_2 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_20 ;
V_2 -> V_69 -> V_74 ( V_2 ) ;
if ( V_2 -> V_11 . V_34 > 1 ) {
for ( V_20 = 0 ; V_20 < V_2 -> V_11 . V_34 ; V_20 ++ ) {
if ( V_2 -> V_11 . V_35 [ V_20 ] )
F_53 ( & V_7 -> V_10 , L_21 ,
V_2 -> V_11 . V_36 [ V_20 ] . V_68 ) ;
}
F_17 ( V_2 -> V_11 . V_35 ) ;
F_17 ( V_2 -> V_11 . V_36 ) ;
F_28 ( V_7 ) ;
} else {
if ( F_49 ( V_7 ) ) {
F_54 ( V_7 -> V_14 , V_2 ) ;
F_17 ( V_2 -> V_11 . V_35 ) ;
F_40 ( V_7 ) ;
} else {
F_54 ( V_7 -> V_14 , V_2 ) ;
}
F_33 ( V_2 ) ;
}
}
void F_57 ( struct V_1 * V_2 )
{
int V_52 , V_63 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ,
struct V_6 , V_10 ) ;
if ( ! F_49 ( V_7 ) )
return;
for ( V_52 = 0 ; V_52 < V_2 -> V_11 . V_34 ; V_52 ++ ) {
for ( V_63 = 0 ; V_63 < V_31 ; V_63 ++ ) {
if ( V_2 -> V_11 . V_35 [ V_52 ] & F_7 ( V_63 ) )
V_2 -> V_69 -> V_70 ( V_2 ,
V_52 , V_63 , true ) ;
}
}
}
