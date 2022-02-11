int T_1 F_1 ( void )
{
V_1 =
F_2 ( L_1 ) ;
if ( ! V_1 )
return - V_2 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static void F_5 ( struct V_3 * V_3 )
{
F_6 ( V_1 , & V_3 -> V_4 ) ;
}
static int F_7 ( T_2 * V_5 , unsigned V_6 , int V_7 , void * V_8 )
{
struct V_3 * V_3 = F_8 ( V_5 , struct V_3 , V_5 ) ;
unsigned long V_9 = ( unsigned long ) V_8 ;
if ( V_9 & V_10 ) {
if ( ( ! V_3 -> V_11 ||
V_3 -> V_11 ( V_3 -> V_12 , V_3 -> V_13 ) ) &&
V_3 -> V_14 )
F_9 ( & V_3 -> V_15 ) ;
}
if ( V_9 & V_16 ) {
unsigned long V_9 ;
F_10 ( & V_3 -> V_12 -> V_17 , V_9 ) ;
if ( * ( V_3 -> V_18 ) == V_3 ) {
* ( V_3 -> V_18 ) = NULL ;
F_5 ( V_3 ) ;
}
F_11 ( & V_3 -> V_12 -> V_17 , V_9 ) ;
}
return 0 ;
}
static void F_12 ( struct V_19 * V_19 ,
T_3 * V_20 , T_4 * V_21 )
{
struct V_3 * V_3 = F_8 ( V_21 , struct V_3 , V_21 ) ;
F_13 ( V_20 , & V_3 -> V_5 ) ;
}
static void F_14 ( struct V_22 * V_23 )
{
struct V_3 * V_3 = F_8 ( V_23 , struct V_3 , V_4 ) ;
T_5 V_24 ;
F_15 ( V_3 -> V_25 , & V_3 -> V_5 , & V_24 ) ;
F_16 ( & V_3 -> V_15 ) ;
F_17 ( V_3 -> V_25 ) ;
F_18 ( V_3 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_3 * V_3 = F_8 ( V_23 , struct V_3 , V_15 ) ;
if ( V_3 -> V_14 )
V_3 -> V_14 ( V_3 -> V_12 , V_3 -> V_13 ) ;
}
static int F_20 ( struct V_26 * V_12 ,
int (* V_11)( struct V_26 * , void * ) ,
void (* V_14)( struct V_26 * , void * ) ,
void * V_13 , struct V_3 * * V_18 , int V_27 )
{
struct V_27 V_28 ;
struct V_29 * V_30 ;
struct V_3 * V_3 ;
int V_31 = 0 ;
unsigned int V_32 ;
V_3 = F_21 ( sizeof( * V_3 ) , V_33 ) ;
if ( ! V_3 )
return - V_2 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_11 = V_11 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_13 = V_13 ;
F_22 ( & V_3 -> V_4 , F_14 ) ;
F_22 ( & V_3 -> V_15 , F_19 ) ;
V_28 = F_23 ( V_27 ) ;
if ( ! V_28 . V_19 ) {
V_31 = - V_34 ;
goto V_35;
}
V_30 = F_24 ( V_28 . V_19 ) ;
if ( F_25 ( V_30 ) ) {
V_31 = F_26 ( V_30 ) ;
goto V_36;
}
V_3 -> V_25 = V_30 ;
F_27 ( & V_12 -> V_17 ) ;
if ( * V_18 ) {
F_28 ( & V_12 -> V_17 ) ;
V_31 = - V_37 ;
goto V_38;
}
* V_18 = V_3 ;
F_28 ( & V_12 -> V_17 ) ;
F_29 ( & V_3 -> V_5 , F_7 ) ;
F_30 ( & V_3 -> V_21 , F_12 ) ;
V_32 = V_28 . V_19 -> V_39 -> V_40 ( V_28 . V_19 , & V_3 -> V_21 ) ;
if ( V_32 & V_10 ) {
if ( ( ! V_11 || V_11 ( V_12 , V_13 ) ) && V_14 )
F_9 ( & V_3 -> V_15 ) ;
}
F_31 ( V_28 ) ;
return 0 ;
V_38:
F_17 ( V_30 ) ;
V_36:
F_31 ( V_28 ) ;
V_35:
F_18 ( V_3 ) ;
return V_31 ;
}
static void F_32 ( struct V_26 * V_12 ,
struct V_3 * * V_18 )
{
unsigned long V_9 ;
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( * V_18 ) {
F_5 ( * V_18 ) ;
* V_18 = NULL ;
}
F_11 ( & V_12 -> V_17 , V_9 ) ;
F_33 ( V_1 ) ;
}
static void F_34 ( struct V_26 * V_12 , void * V_41 )
{
if ( F_35 ( F_36 ( V_12 ) && ! V_12 -> V_42 ) )
F_37 ( V_12 -> V_30 [ 0 ] . V_43 , 1 ) ;
}
void F_38 ( struct V_26 * V_12 )
{
struct V_44 * V_45 = V_12 -> V_45 ;
unsigned long V_9 ;
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( F_39 ( ! F_36 ( V_12 ) ) ) {
if ( V_12 -> V_46 )
F_40 ( V_45 , 0 ) ;
} else if ( ! V_12 -> V_30 [ 0 ] . V_47 ) {
if ( V_12 -> V_46 )
F_40 ( V_45 , 0 ) ;
else
F_41 ( V_45 -> V_48 ) ;
V_12 -> V_30 [ 0 ] . V_47 = true ;
}
F_11 ( & V_12 -> V_17 , V_9 ) ;
}
static int F_42 ( struct V_26 * V_12 ,
void * V_41 )
{
struct V_44 * V_45 = V_12 -> V_45 ;
unsigned long V_9 ;
int V_31 = 0 ;
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( F_39 ( ! F_36 ( V_12 ) ) ) {
if ( V_12 -> V_46 )
F_40 ( V_45 , 1 ) ;
} else if ( V_12 -> V_30 [ 0 ] . V_47 && ! V_12 -> V_42 ) {
if ( V_12 -> V_46 ) {
if ( ! F_43 ( V_45 ) )
V_31 = 1 ;
} else
F_44 ( V_45 -> V_48 ) ;
V_12 -> V_30 [ 0 ] . V_47 = ( V_31 > 0 ) ;
}
F_11 ( & V_12 -> V_17 , V_9 ) ;
return V_31 ;
}
void F_45 ( struct V_26 * V_12 )
{
if ( F_42 ( V_12 , NULL ) > 0 )
F_34 ( V_12 , NULL ) ;
}
static T_6 F_46 ( int V_48 , void * V_49 )
{
struct V_26 * V_12 = V_49 ;
unsigned long V_9 ;
int V_31 = V_50 ;
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( ! V_12 -> V_46 ) {
F_41 ( V_12 -> V_45 -> V_48 ) ;
V_12 -> V_30 [ 0 ] . V_47 = true ;
V_31 = V_51 ;
} else if ( ! V_12 -> V_30 [ 0 ] . V_47 &&
F_47 ( V_12 -> V_45 ) ) {
V_12 -> V_30 [ 0 ] . V_47 = true ;
V_31 = V_51 ;
}
F_11 ( & V_12 -> V_17 , V_9 ) ;
if ( V_31 == V_51 )
F_34 ( V_12 , NULL ) ;
return V_31 ;
}
static int F_48 ( struct V_26 * V_12 )
{
if ( ! F_49 ( V_12 ) )
return - V_52 ;
if ( ! V_12 -> V_45 -> V_48 )
return - V_53 ;
V_12 -> V_30 = F_21 ( sizeof( struct V_54 ) , V_33 ) ;
if ( ! V_12 -> V_30 )
return - V_2 ;
V_12 -> V_55 = 1 ;
V_12 -> V_30 [ 0 ] . V_47 = V_12 -> V_42 ;
if ( V_12 -> V_46 )
F_40 ( V_12 -> V_45 , ! V_12 -> V_30 [ 0 ] . V_47 ) ;
V_12 -> V_56 = V_57 ;
return 0 ;
}
static int F_50 ( struct V_26 * V_12 , int V_27 )
{
struct V_44 * V_45 = V_12 -> V_45 ;
unsigned long V_58 = V_59 ;
struct V_29 * V_43 ;
unsigned long V_9 ;
int V_31 ;
if ( V_12 -> V_30 [ 0 ] . V_43 ) {
F_51 ( V_45 -> V_48 , V_12 ) ;
F_18 ( V_12 -> V_30 [ 0 ] . V_60 ) ;
F_17 ( V_12 -> V_30 [ 0 ] . V_43 ) ;
V_12 -> V_30 [ 0 ] . V_43 = NULL ;
}
if ( V_27 < 0 )
return 0 ;
V_12 -> V_30 [ 0 ] . V_60 = F_52 ( V_33 , L_2 ,
F_53 ( V_45 ) ) ;
if ( ! V_12 -> V_30 [ 0 ] . V_60 )
return - V_2 ;
V_43 = F_54 ( V_27 ) ;
if ( F_25 ( V_43 ) ) {
F_18 ( V_12 -> V_30 [ 0 ] . V_60 ) ;
return F_26 ( V_43 ) ;
}
V_12 -> V_30 [ 0 ] . V_43 = V_43 ;
if ( ! V_12 -> V_46 )
V_58 = 0 ;
V_31 = F_55 ( V_45 -> V_48 , F_46 ,
V_58 , V_12 -> V_30 [ 0 ] . V_60 , V_12 ) ;
if ( V_31 ) {
V_12 -> V_30 [ 0 ] . V_43 = NULL ;
F_18 ( V_12 -> V_30 [ 0 ] . V_60 ) ;
F_17 ( V_43 ) ;
return V_31 ;
}
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( ! V_12 -> V_46 && V_12 -> V_30 [ 0 ] . V_47 )
F_41 ( V_45 -> V_48 ) ;
F_11 ( & V_12 -> V_17 , V_9 ) ;
return 0 ;
}
static void F_56 ( struct V_26 * V_12 )
{
F_50 ( V_12 , - 1 ) ;
F_32 ( V_12 , & V_12 -> V_30 [ 0 ] . V_61 ) ;
F_32 ( V_12 , & V_12 -> V_30 [ 0 ] . V_62 ) ;
V_12 -> V_56 = V_63 ;
V_12 -> V_55 = 0 ;
F_18 ( V_12 -> V_30 ) ;
}
static T_6 F_57 ( int V_48 , void * V_64 )
{
struct V_29 * V_43 = V_64 ;
F_37 ( V_43 , 1 ) ;
return V_51 ;
}
static int F_58 ( struct V_26 * V_12 , int V_65 , bool V_66 )
{
struct V_44 * V_45 = V_12 -> V_45 ;
int V_31 ;
if ( ! F_49 ( V_12 ) )
return - V_52 ;
V_12 -> V_30 = F_21 ( V_65 * sizeof( struct V_54 ) , V_33 ) ;
if ( ! V_12 -> V_30 )
return - V_2 ;
if ( V_66 ) {
int V_67 ;
V_12 -> V_66 = F_21 ( V_65 * sizeof( struct V_68 ) ,
V_33 ) ;
if ( ! V_12 -> V_66 ) {
F_18 ( V_12 -> V_30 ) ;
return - V_2 ;
}
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
V_12 -> V_66 [ V_67 ] . V_69 = V_67 ;
V_31 = F_59 ( V_45 , V_12 -> V_66 , 1 , V_65 ) ;
if ( V_31 < V_65 ) {
if ( V_31 > 0 )
F_60 ( V_45 ) ;
F_18 ( V_12 -> V_66 ) ;
F_18 ( V_12 -> V_30 ) ;
return V_31 ;
}
} else {
V_31 = F_61 ( V_45 , 1 , V_65 ) ;
if ( V_31 < V_65 ) {
if ( V_31 > 0 )
F_62 ( V_45 ) ;
F_18 ( V_12 -> V_30 ) ;
return V_31 ;
}
}
V_12 -> V_55 = V_65 ;
V_12 -> V_56 = V_66 ? V_70 :
V_71 ;
if ( ! V_66 ) {
V_12 -> V_72 = F_63 ( V_65 * 2 - 1 ) - 1 ;
}
return 0 ;
}
static int F_64 ( struct V_26 * V_12 ,
int V_73 , int V_27 , bool V_66 )
{
struct V_44 * V_45 = V_12 -> V_45 ;
int V_48 = V_66 ? V_12 -> V_66 [ V_73 ] . V_73 : V_45 -> V_48 + V_73 ;
char * V_60 = V_66 ? L_3 : L_4 ;
struct V_29 * V_43 ;
int V_31 ;
if ( V_73 >= V_12 -> V_55 )
return - V_52 ;
if ( V_12 -> V_30 [ V_73 ] . V_43 ) {
F_51 ( V_48 , V_12 -> V_30 [ V_73 ] . V_43 ) ;
F_18 ( V_12 -> V_30 [ V_73 ] . V_60 ) ;
F_17 ( V_12 -> V_30 [ V_73 ] . V_43 ) ;
V_12 -> V_30 [ V_73 ] . V_43 = NULL ;
}
if ( V_27 < 0 )
return 0 ;
V_12 -> V_30 [ V_73 ] . V_60 = F_52 ( V_33 , L_5 ,
V_60 , V_73 , F_53 ( V_45 ) ) ;
if ( ! V_12 -> V_30 [ V_73 ] . V_60 )
return - V_2 ;
V_43 = F_54 ( V_27 ) ;
if ( F_25 ( V_43 ) ) {
F_18 ( V_12 -> V_30 [ V_73 ] . V_60 ) ;
return F_26 ( V_43 ) ;
}
if ( V_66 ) {
struct V_74 V_75 ;
F_65 ( V_48 , & V_75 ) ;
F_66 ( V_48 , & V_75 ) ;
}
V_31 = F_55 ( V_48 , F_57 , 0 ,
V_12 -> V_30 [ V_73 ] . V_60 , V_43 ) ;
if ( V_31 ) {
F_18 ( V_12 -> V_30 [ V_73 ] . V_60 ) ;
F_17 ( V_43 ) ;
return V_31 ;
}
V_12 -> V_30 [ V_73 ] . V_43 = V_43 ;
return 0 ;
}
static int F_67 ( struct V_26 * V_12 , unsigned V_76 ,
unsigned V_77 , T_7 * V_78 , bool V_66 )
{
int V_67 , V_79 , V_31 = 0 ;
if ( V_76 + V_77 > V_12 -> V_55 )
return - V_52 ;
for ( V_67 = 0 , V_79 = V_76 ; V_67 < V_77 && ! V_31 ; V_67 ++ , V_79 ++ ) {
int V_27 = V_78 ? V_78 [ V_67 ] : - 1 ;
V_31 = F_64 ( V_12 , V_79 , V_27 , V_66 ) ;
}
if ( V_31 ) {
for ( -- V_79 ; V_79 >= V_76 ; V_79 -- )
F_64 ( V_12 , V_79 , - 1 , V_66 ) ;
}
return V_31 ;
}
static void F_68 ( struct V_26 * V_12 , bool V_66 )
{
struct V_44 * V_45 = V_12 -> V_45 ;
int V_67 ;
F_67 ( V_12 , 0 , V_12 -> V_55 , NULL , V_66 ) ;
for ( V_67 = 0 ; V_67 < V_12 -> V_55 ; V_67 ++ ) {
F_32 ( V_12 , & V_12 -> V_30 [ V_67 ] . V_61 ) ;
F_32 ( V_12 , & V_12 -> V_30 [ V_67 ] . V_62 ) ;
}
if ( V_66 ) {
F_60 ( V_12 -> V_45 ) ;
F_18 ( V_12 -> V_66 ) ;
} else
F_62 ( V_45 ) ;
V_12 -> V_56 = V_63 ;
V_12 -> V_55 = 0 ;
F_18 ( V_12 -> V_30 ) ;
}
static int F_69 ( struct V_26 * V_12 ,
unsigned V_80 , unsigned V_76 ,
unsigned V_77 , T_8 V_9 , void * V_13 )
{
if ( ! F_36 ( V_12 ) || V_76 != 0 || V_77 != 1 )
return - V_52 ;
if ( V_9 & V_81 ) {
F_45 ( V_12 ) ;
} else if ( V_9 & V_82 ) {
T_9 V_61 = * ( T_9 * ) V_13 ;
if ( V_61 )
F_45 ( V_12 ) ;
} else if ( V_9 & V_83 ) {
T_7 V_27 = * ( T_7 * ) V_13 ;
if ( V_27 >= 0 )
return F_20 ( V_12 , F_42 ,
F_34 , NULL ,
& V_12 -> V_30 [ 0 ] . V_61 , V_27 ) ;
F_32 ( V_12 , & V_12 -> V_30 [ 0 ] . V_61 ) ;
}
return 0 ;
}
static int F_70 ( struct V_26 * V_12 ,
unsigned V_80 , unsigned V_76 ,
unsigned V_77 , T_8 V_9 , void * V_13 )
{
if ( ! F_36 ( V_12 ) || V_76 != 0 || V_77 != 1 )
return - V_52 ;
if ( V_9 & V_81 ) {
F_38 ( V_12 ) ;
} else if ( V_9 & V_82 ) {
T_9 V_62 = * ( T_9 * ) V_13 ;
if ( V_62 )
F_38 ( V_12 ) ;
} else if ( V_9 & V_83 ) {
return - V_84 ;
}
return 0 ;
}
static int F_71 ( struct V_26 * V_12 ,
unsigned V_80 , unsigned V_76 ,
unsigned V_77 , T_8 V_9 , void * V_13 )
{
if ( F_36 ( V_12 ) && ! V_77 && ( V_9 & V_81 ) ) {
F_56 ( V_12 ) ;
return 0 ;
}
if ( ! ( F_36 ( V_12 ) || F_49 ( V_12 ) ) || V_76 != 0 || V_77 != 1 )
return - V_52 ;
if ( V_9 & V_83 ) {
T_7 V_27 = * ( T_7 * ) V_13 ;
int V_31 ;
if ( F_36 ( V_12 ) )
return F_50 ( V_12 , V_27 ) ;
V_31 = F_48 ( V_12 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_50 ( V_12 , V_27 ) ;
if ( V_31 )
F_56 ( V_12 ) ;
return V_31 ;
}
if ( ! F_36 ( V_12 ) )
return - V_52 ;
if ( V_9 & V_81 ) {
F_34 ( V_12 , NULL ) ;
} else if ( V_9 & V_82 ) {
T_9 V_43 = * ( T_9 * ) V_13 ;
if ( V_43 )
F_34 ( V_12 , NULL ) ;
}
return 0 ;
}
static int F_72 ( struct V_26 * V_12 ,
unsigned V_80 , unsigned V_76 ,
unsigned V_77 , T_8 V_9 , void * V_13 )
{
int V_67 ;
bool V_66 = ( V_80 == V_70 ) ? true : false ;
if ( F_73 ( V_12 , V_80 ) && ! V_77 && ( V_9 & V_81 ) ) {
F_68 ( V_12 , V_66 ) ;
return 0 ;
}
if ( ! ( F_73 ( V_12 , V_80 ) || F_49 ( V_12 ) ) )
return - V_52 ;
if ( V_9 & V_83 ) {
T_7 * V_78 = V_13 ;
int V_31 ;
if ( V_12 -> V_56 == V_80 )
return F_67 ( V_12 , V_76 , V_77 ,
V_78 , V_66 ) ;
V_31 = F_58 ( V_12 , V_76 + V_77 , V_66 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_67 ( V_12 , V_76 , V_77 , V_78 , V_66 ) ;
if ( V_31 )
F_68 ( V_12 , V_66 ) ;
return V_31 ;
}
if ( ! F_73 ( V_12 , V_80 ) || V_76 + V_77 > V_12 -> V_55 )
return - V_52 ;
for ( V_67 = V_76 ; V_67 < V_76 + V_77 ; V_67 ++ ) {
if ( ! V_12 -> V_30 [ V_67 ] . V_43 )
continue;
if ( V_9 & V_81 ) {
F_37 ( V_12 -> V_30 [ V_67 ] . V_43 , 1 ) ;
} else if ( V_9 & V_82 ) {
T_9 * V_85 = V_13 ;
if ( V_85 [ V_67 - V_76 ] )
F_37 ( V_12 -> V_30 [ V_67 ] . V_43 , 1 ) ;
}
}
return 0 ;
}
static int F_74 ( struct V_29 * * V_30 ,
T_8 V_9 , void * V_13 )
{
T_7 V_27 = * ( T_7 * ) V_13 ;
if ( ! ( V_9 & V_86 ) )
return - V_52 ;
if ( V_9 & V_81 ) {
if ( * V_30 )
F_37 ( * V_30 , 1 ) ;
return 0 ;
} else if ( V_9 & V_82 ) {
T_9 V_43 = * ( T_9 * ) V_13 ;
if ( V_43 && * V_30 )
F_37 ( * V_30 , 1 ) ;
return 0 ;
}
if ( V_27 == - 1 ) {
if ( * V_30 )
F_17 ( * V_30 ) ;
* V_30 = NULL ;
return 0 ;
} else if ( V_27 >= 0 ) {
struct V_29 * V_87 ;
V_87 = F_54 ( V_27 ) ;
if ( F_25 ( V_87 ) )
return F_26 ( V_87 ) ;
if ( * V_30 )
F_17 ( * V_30 ) ;
* V_30 = V_87 ;
return 0 ;
} else
return - V_52 ;
}
static int F_75 ( struct V_26 * V_12 ,
unsigned V_80 , unsigned V_76 ,
unsigned V_77 , T_8 V_9 , void * V_13 )
{
if ( V_80 != V_88 )
return - V_52 ;
return F_74 ( & V_12 -> V_89 , V_9 , V_13 ) ;
}
static int F_76 ( struct V_26 * V_12 ,
unsigned V_80 , unsigned V_76 ,
unsigned V_77 , T_8 V_9 , void * V_13 )
{
if ( V_80 != V_90 || V_76 != 0 || V_77 != 1 )
return - V_52 ;
return F_74 ( & V_12 -> V_91 , V_9 , V_13 ) ;
}
int F_77 ( struct V_26 * V_12 , T_8 V_9 ,
unsigned V_80 , unsigned V_76 , unsigned V_77 ,
void * V_13 )
{
int (* F_78)( struct V_26 * V_12 , unsigned V_80 ,
unsigned V_76 , unsigned V_77 , T_8 V_9 ,
void * V_13 ) = NULL ;
switch ( V_80 ) {
case V_57 :
switch ( V_9 & V_92 ) {
case V_93 :
F_78 = F_70 ;
break;
case V_94 :
F_78 = F_69 ;
break;
case V_95 :
F_78 = F_71 ;
break;
}
break;
case V_71 :
case V_70 :
switch ( V_9 & V_92 ) {
case V_93 :
case V_94 :
break;
case V_95 :
F_78 = F_72 ;
break;
}
break;
case V_88 :
switch ( V_9 & V_92 ) {
case V_95 :
if ( F_79 ( V_12 -> V_45 ) )
F_78 = F_75 ;
break;
}
break;
case V_90 :
switch ( V_9 & V_92 ) {
case V_95 :
F_78 = F_76 ;
break;
}
break;
}
if ( ! F_78 )
return - V_84 ;
return F_78 ( V_12 , V_80 , V_76 , V_77 , V_9 , V_13 ) ;
}
