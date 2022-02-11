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
struct V_19 * V_19 = NULL ;
struct V_28 * V_29 = NULL ;
struct V_3 * V_3 ;
int V_30 = 0 ;
unsigned int V_31 ;
V_3 = F_21 ( sizeof( * V_3 ) , V_32 ) ;
if ( ! V_3 )
return - V_2 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_11 = V_11 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_13 = V_13 ;
F_22 ( & V_3 -> V_4 , F_14 ) ;
F_22 ( & V_3 -> V_15 , F_19 ) ;
V_19 = F_23 ( V_27 ) ;
if ( F_24 ( V_19 ) ) {
V_30 = F_25 ( V_19 ) ;
goto V_33;
}
V_29 = F_26 ( V_19 ) ;
if ( F_24 ( V_29 ) ) {
V_30 = F_25 ( V_29 ) ;
goto V_33;
}
V_3 -> V_25 = V_29 ;
F_27 ( & V_12 -> V_17 ) ;
if ( * V_18 ) {
F_28 ( & V_12 -> V_17 ) ;
V_30 = - V_34 ;
goto V_33;
}
* V_18 = V_3 ;
F_28 ( & V_12 -> V_17 ) ;
F_29 ( & V_3 -> V_5 , F_7 ) ;
F_30 ( & V_3 -> V_21 , F_12 ) ;
V_31 = V_19 -> V_35 -> V_36 ( V_19 , & V_3 -> V_21 ) ;
if ( V_31 & V_10 ) {
if ( ( ! V_11 || V_11 ( V_12 , V_13 ) ) && V_14 )
F_9 ( & V_3 -> V_15 ) ;
}
F_31 ( V_19 ) ;
return 0 ;
V_33:
if ( V_29 && ! F_24 ( V_29 ) )
F_17 ( V_29 ) ;
if ( V_19 && ! F_24 ( V_19 ) )
F_31 ( V_19 ) ;
F_18 ( V_3 ) ;
return V_30 ;
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
static void F_34 ( struct V_26 * V_12 , void * V_37 )
{
if ( F_35 ( F_36 ( V_12 ) && ! V_12 -> V_38 ) )
F_37 ( V_12 -> V_29 [ 0 ] . V_39 , 1 ) ;
}
void F_38 ( struct V_26 * V_12 )
{
struct V_40 * V_41 = V_12 -> V_41 ;
unsigned long V_9 ;
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( F_39 ( ! F_36 ( V_12 ) ) ) {
if ( V_12 -> V_42 )
F_40 ( V_41 , 0 ) ;
} else if ( ! V_12 -> V_29 [ 0 ] . V_43 ) {
if ( V_12 -> V_42 )
F_40 ( V_41 , 0 ) ;
else
F_41 ( V_41 -> V_44 ) ;
V_12 -> V_29 [ 0 ] . V_43 = true ;
}
F_11 ( & V_12 -> V_17 , V_9 ) ;
}
static int F_42 ( struct V_26 * V_12 ,
void * V_37 )
{
struct V_40 * V_41 = V_12 -> V_41 ;
unsigned long V_9 ;
int V_30 = 0 ;
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( F_39 ( ! F_36 ( V_12 ) ) ) {
if ( V_12 -> V_42 )
F_40 ( V_41 , 1 ) ;
} else if ( V_12 -> V_29 [ 0 ] . V_43 && ! V_12 -> V_38 ) {
if ( V_12 -> V_42 ) {
if ( ! F_43 ( V_41 ) )
V_30 = 1 ;
} else
F_44 ( V_41 -> V_44 ) ;
V_12 -> V_29 [ 0 ] . V_43 = ( V_30 > 0 ) ;
}
F_11 ( & V_12 -> V_17 , V_9 ) ;
return V_30 ;
}
void F_45 ( struct V_26 * V_12 )
{
if ( F_42 ( V_12 , NULL ) > 0 )
F_34 ( V_12 , NULL ) ;
}
static T_6 F_46 ( int V_44 , void * V_45 )
{
struct V_26 * V_12 = V_45 ;
unsigned long V_9 ;
int V_30 = V_46 ;
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( ! V_12 -> V_42 ) {
F_41 ( V_12 -> V_41 -> V_44 ) ;
V_12 -> V_29 [ 0 ] . V_43 = true ;
V_30 = V_47 ;
} else if ( ! V_12 -> V_29 [ 0 ] . V_43 &&
F_47 ( V_12 -> V_41 ) ) {
V_12 -> V_29 [ 0 ] . V_43 = true ;
V_30 = V_47 ;
}
F_11 ( & V_12 -> V_17 , V_9 ) ;
if ( V_30 == V_47 )
F_34 ( V_12 , NULL ) ;
return V_30 ;
}
static int F_48 ( struct V_26 * V_12 )
{
if ( ! F_49 ( V_12 ) )
return - V_48 ;
if ( ! V_12 -> V_41 -> V_44 )
return - V_49 ;
V_12 -> V_29 = F_21 ( sizeof( struct V_50 ) , V_32 ) ;
if ( ! V_12 -> V_29 )
return - V_2 ;
V_12 -> V_51 = 1 ;
V_12 -> V_29 [ 0 ] . V_43 = V_12 -> V_38 ;
if ( V_12 -> V_42 )
F_40 ( V_12 -> V_41 , ! V_12 -> V_29 [ 0 ] . V_43 ) ;
V_12 -> V_52 = V_53 ;
return 0 ;
}
static int F_50 ( struct V_26 * V_12 , int V_27 )
{
struct V_40 * V_41 = V_12 -> V_41 ;
unsigned long V_54 = V_55 ;
struct V_28 * V_39 ;
unsigned long V_9 ;
int V_30 ;
if ( V_12 -> V_29 [ 0 ] . V_39 ) {
F_51 ( V_41 -> V_44 , V_12 ) ;
F_18 ( V_12 -> V_29 [ 0 ] . V_56 ) ;
F_17 ( V_12 -> V_29 [ 0 ] . V_39 ) ;
V_12 -> V_29 [ 0 ] . V_39 = NULL ;
}
if ( V_27 < 0 )
return 0 ;
V_12 -> V_29 [ 0 ] . V_56 = F_52 ( V_32 , L_2 ,
F_53 ( V_41 ) ) ;
if ( ! V_12 -> V_29 [ 0 ] . V_56 )
return - V_2 ;
V_39 = F_54 ( V_27 ) ;
if ( F_24 ( V_39 ) ) {
F_18 ( V_12 -> V_29 [ 0 ] . V_56 ) ;
return F_25 ( V_39 ) ;
}
V_12 -> V_29 [ 0 ] . V_39 = V_39 ;
if ( ! V_12 -> V_42 )
V_54 = 0 ;
V_30 = F_55 ( V_41 -> V_44 , F_46 ,
V_54 , V_12 -> V_29 [ 0 ] . V_56 , V_12 ) ;
if ( V_30 ) {
V_12 -> V_29 [ 0 ] . V_39 = NULL ;
F_18 ( V_12 -> V_29 [ 0 ] . V_56 ) ;
F_17 ( V_39 ) ;
return V_30 ;
}
F_10 ( & V_12 -> V_17 , V_9 ) ;
if ( ! V_12 -> V_42 && V_12 -> V_29 [ 0 ] . V_43 )
F_41 ( V_41 -> V_44 ) ;
F_11 ( & V_12 -> V_17 , V_9 ) ;
return 0 ;
}
static void F_56 ( struct V_26 * V_12 )
{
F_50 ( V_12 , - 1 ) ;
F_32 ( V_12 , & V_12 -> V_29 [ 0 ] . V_57 ) ;
F_32 ( V_12 , & V_12 -> V_29 [ 0 ] . V_58 ) ;
V_12 -> V_52 = V_59 ;
V_12 -> V_51 = 0 ;
F_18 ( V_12 -> V_29 ) ;
}
static T_6 F_57 ( int V_44 , void * V_60 )
{
struct V_28 * V_39 = V_60 ;
F_37 ( V_39 , 1 ) ;
return V_47 ;
}
static int F_58 ( struct V_26 * V_12 , int V_61 , bool V_62 )
{
struct V_40 * V_41 = V_12 -> V_41 ;
int V_30 ;
if ( ! F_49 ( V_12 ) )
return - V_48 ;
V_12 -> V_29 = F_21 ( V_61 * sizeof( struct V_50 ) , V_32 ) ;
if ( ! V_12 -> V_29 )
return - V_2 ;
if ( V_62 ) {
int V_63 ;
V_12 -> V_62 = F_21 ( V_61 * sizeof( struct V_64 ) ,
V_32 ) ;
if ( ! V_12 -> V_62 ) {
F_18 ( V_12 -> V_29 ) ;
return - V_2 ;
}
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ )
V_12 -> V_62 [ V_63 ] . V_65 = V_63 ;
V_30 = F_59 ( V_41 , V_12 -> V_62 , V_61 ) ;
if ( V_30 ) {
F_18 ( V_12 -> V_62 ) ;
F_18 ( V_12 -> V_29 ) ;
return V_30 ;
}
} else {
V_30 = F_60 ( V_41 , V_61 ) ;
if ( V_30 ) {
F_18 ( V_12 -> V_29 ) ;
return V_30 ;
}
}
V_12 -> V_51 = V_61 ;
V_12 -> V_52 = V_62 ? V_66 :
V_67 ;
if ( ! V_62 ) {
V_12 -> V_68 = F_61 ( V_61 * 2 - 1 ) - 1 ;
}
return 0 ;
}
static int F_62 ( struct V_26 * V_12 ,
int V_69 , int V_27 , bool V_62 )
{
struct V_40 * V_41 = V_12 -> V_41 ;
int V_44 = V_62 ? V_12 -> V_62 [ V_69 ] . V_69 : V_41 -> V_44 + V_69 ;
char * V_56 = V_62 ? L_3 : L_4 ;
struct V_28 * V_39 ;
int V_30 ;
if ( V_69 >= V_12 -> V_51 )
return - V_48 ;
if ( V_12 -> V_29 [ V_69 ] . V_39 ) {
F_51 ( V_44 , V_12 -> V_29 [ V_69 ] . V_39 ) ;
F_18 ( V_12 -> V_29 [ V_69 ] . V_56 ) ;
F_17 ( V_12 -> V_29 [ V_69 ] . V_39 ) ;
V_12 -> V_29 [ V_69 ] . V_39 = NULL ;
}
if ( V_27 < 0 )
return 0 ;
V_12 -> V_29 [ V_69 ] . V_56 = F_52 ( V_32 , L_5 ,
V_56 , V_69 , F_53 ( V_41 ) ) ;
if ( ! V_12 -> V_29 [ V_69 ] . V_56 )
return - V_2 ;
V_39 = F_54 ( V_27 ) ;
if ( F_24 ( V_39 ) ) {
F_18 ( V_12 -> V_29 [ V_69 ] . V_56 ) ;
return F_25 ( V_39 ) ;
}
V_30 = F_55 ( V_44 , F_57 , 0 ,
V_12 -> V_29 [ V_69 ] . V_56 , V_39 ) ;
if ( V_30 ) {
F_18 ( V_12 -> V_29 [ V_69 ] . V_56 ) ;
F_17 ( V_39 ) ;
return V_30 ;
}
V_12 -> V_29 [ V_69 ] . V_39 = V_39 ;
return 0 ;
}
static int F_63 ( struct V_26 * V_12 , unsigned V_70 ,
unsigned V_71 , T_7 * V_72 , bool V_62 )
{
int V_63 , V_73 , V_30 = 0 ;
if ( V_70 + V_71 > V_12 -> V_51 )
return - V_48 ;
for ( V_63 = 0 , V_73 = V_70 ; V_63 < V_71 && ! V_30 ; V_63 ++ , V_73 ++ ) {
int V_27 = V_72 ? V_72 [ V_63 ] : - 1 ;
V_30 = F_62 ( V_12 , V_73 , V_27 , V_62 ) ;
}
if ( V_30 ) {
for ( -- V_73 ; V_73 >= V_70 ; V_73 -- )
F_62 ( V_12 , V_73 , - 1 , V_62 ) ;
}
return V_30 ;
}
static void F_64 ( struct V_26 * V_12 , bool V_62 )
{
struct V_40 * V_41 = V_12 -> V_41 ;
int V_63 ;
F_63 ( V_12 , 0 , V_12 -> V_51 , NULL , V_62 ) ;
for ( V_63 = 0 ; V_63 < V_12 -> V_51 ; V_63 ++ ) {
F_32 ( V_12 , & V_12 -> V_29 [ V_63 ] . V_57 ) ;
F_32 ( V_12 , & V_12 -> V_29 [ V_63 ] . V_58 ) ;
}
if ( V_62 ) {
F_65 ( V_12 -> V_41 ) ;
F_18 ( V_12 -> V_62 ) ;
} else
F_66 ( V_41 ) ;
V_12 -> V_52 = V_59 ;
V_12 -> V_51 = 0 ;
F_18 ( V_12 -> V_29 ) ;
}
static int F_67 ( struct V_26 * V_12 ,
unsigned V_74 , unsigned V_70 ,
unsigned V_71 , T_8 V_9 , void * V_13 )
{
if ( ! F_36 ( V_12 ) || V_70 != 0 || V_71 != 1 )
return - V_48 ;
if ( V_9 & V_75 ) {
F_45 ( V_12 ) ;
} else if ( V_9 & V_76 ) {
T_9 V_57 = * ( T_9 * ) V_13 ;
if ( V_57 )
F_45 ( V_12 ) ;
} else if ( V_9 & V_77 ) {
T_7 V_27 = * ( T_7 * ) V_13 ;
if ( V_27 >= 0 )
return F_20 ( V_12 , F_42 ,
F_34 , NULL ,
& V_12 -> V_29 [ 0 ] . V_57 , V_27 ) ;
F_32 ( V_12 , & V_12 -> V_29 [ 0 ] . V_57 ) ;
}
return 0 ;
}
static int F_68 ( struct V_26 * V_12 ,
unsigned V_74 , unsigned V_70 ,
unsigned V_71 , T_8 V_9 , void * V_13 )
{
if ( ! F_36 ( V_12 ) || V_70 != 0 || V_71 != 1 )
return - V_48 ;
if ( V_9 & V_75 ) {
F_38 ( V_12 ) ;
} else if ( V_9 & V_76 ) {
T_9 V_58 = * ( T_9 * ) V_13 ;
if ( V_58 )
F_38 ( V_12 ) ;
} else if ( V_9 & V_77 ) {
return - V_78 ;
}
return 0 ;
}
static int F_69 ( struct V_26 * V_12 ,
unsigned V_74 , unsigned V_70 ,
unsigned V_71 , T_8 V_9 , void * V_13 )
{
if ( F_36 ( V_12 ) && ! V_71 && ( V_9 & V_75 ) ) {
F_56 ( V_12 ) ;
return 0 ;
}
if ( ! ( F_36 ( V_12 ) || F_49 ( V_12 ) ) || V_70 != 0 || V_71 != 1 )
return - V_48 ;
if ( V_9 & V_77 ) {
T_7 V_27 = * ( T_7 * ) V_13 ;
int V_30 ;
if ( F_36 ( V_12 ) )
return F_50 ( V_12 , V_27 ) ;
V_30 = F_48 ( V_12 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_50 ( V_12 , V_27 ) ;
if ( V_30 )
F_56 ( V_12 ) ;
return V_30 ;
}
if ( ! F_36 ( V_12 ) )
return - V_48 ;
if ( V_9 & V_75 ) {
F_34 ( V_12 , NULL ) ;
} else if ( V_9 & V_76 ) {
T_9 V_39 = * ( T_9 * ) V_13 ;
if ( V_39 )
F_34 ( V_12 , NULL ) ;
}
return 0 ;
}
static int F_70 ( struct V_26 * V_12 ,
unsigned V_74 , unsigned V_70 ,
unsigned V_71 , T_8 V_9 , void * V_13 )
{
int V_63 ;
bool V_62 = ( V_74 == V_66 ) ? true : false ;
if ( F_71 ( V_12 , V_74 ) && ! V_71 && ( V_9 & V_75 ) ) {
F_64 ( V_12 , V_62 ) ;
return 0 ;
}
if ( ! ( F_71 ( V_12 , V_74 ) || F_49 ( V_12 ) ) )
return - V_48 ;
if ( V_9 & V_77 ) {
T_7 * V_72 = V_13 ;
int V_30 ;
if ( V_12 -> V_52 == V_74 )
return F_63 ( V_12 , V_70 , V_71 ,
V_72 , V_62 ) ;
V_30 = F_58 ( V_12 , V_70 + V_71 , V_62 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_63 ( V_12 , V_70 , V_71 , V_72 , V_62 ) ;
if ( V_30 )
F_64 ( V_12 , V_62 ) ;
return V_30 ;
}
if ( ! F_71 ( V_12 , V_74 ) || V_70 + V_71 > V_12 -> V_51 )
return - V_48 ;
for ( V_63 = V_70 ; V_63 < V_70 + V_71 ; V_63 ++ ) {
if ( ! V_12 -> V_29 [ V_63 ] . V_39 )
continue;
if ( V_9 & V_75 ) {
F_37 ( V_12 -> V_29 [ V_63 ] . V_39 , 1 ) ;
} else if ( V_9 & V_76 ) {
T_9 * V_79 = V_13 ;
if ( V_79 [ V_63 - V_70 ] )
F_37 ( V_12 -> V_29 [ V_63 ] . V_39 , 1 ) ;
}
}
return 0 ;
}
static int F_72 ( struct V_26 * V_12 ,
unsigned V_74 , unsigned V_70 ,
unsigned V_71 , T_8 V_9 , void * V_13 )
{
T_7 V_27 = * ( T_7 * ) V_13 ;
struct V_40 * V_41 = V_12 -> V_41 ;
if ( ( V_74 != V_80 ) ||
! ( V_9 & V_81 ) )
return - V_48 ;
if ( V_9 & V_75 ) {
F_73 ( & V_41 -> V_82 ) ;
if ( V_12 -> V_83 )
F_37 ( V_12 -> V_83 , 1 ) ;
F_74 ( & V_41 -> V_82 ) ;
return 0 ;
} else if ( V_9 & V_76 ) {
T_9 V_39 = * ( T_9 * ) V_13 ;
F_73 ( & V_41 -> V_82 ) ;
if ( V_39 && V_12 -> V_83 )
F_37 ( V_12 -> V_83 , 1 ) ;
F_74 ( & V_41 -> V_82 ) ;
return 0 ;
}
if ( V_27 == - 1 ) {
F_73 ( & V_41 -> V_82 ) ;
if ( V_12 -> V_83 )
F_17 ( V_12 -> V_83 ) ;
V_12 -> V_83 = NULL ;
F_74 ( & V_41 -> V_82 ) ;
return 0 ;
} else if ( V_27 >= 0 ) {
struct V_28 * V_84 ;
V_84 = F_54 ( V_27 ) ;
if ( F_24 ( V_84 ) )
return F_25 ( V_84 ) ;
F_73 ( & V_41 -> V_82 ) ;
if ( V_12 -> V_83 )
F_17 ( V_12 -> V_83 ) ;
V_12 -> V_83 = V_84 ;
F_74 ( & V_41 -> V_82 ) ;
return 0 ;
} else
return - V_48 ;
}
int F_75 ( struct V_26 * V_12 , T_8 V_9 ,
unsigned V_74 , unsigned V_70 , unsigned V_71 ,
void * V_13 )
{
int (* F_76)( struct V_26 * V_12 , unsigned V_74 ,
unsigned V_70 , unsigned V_71 , T_8 V_9 ,
void * V_13 ) = NULL ;
switch ( V_74 ) {
case V_53 :
switch ( V_9 & V_85 ) {
case V_86 :
F_76 = F_68 ;
break;
case V_87 :
F_76 = F_67 ;
break;
case V_88 :
F_76 = F_69 ;
break;
}
break;
case V_67 :
case V_66 :
switch ( V_9 & V_85 ) {
case V_86 :
case V_87 :
break;
case V_88 :
F_76 = F_70 ;
break;
}
break;
case V_80 :
switch ( V_9 & V_85 ) {
case V_88 :
if ( F_77 ( V_12 -> V_41 ) )
F_76 = F_72 ;
break;
}
}
if ( ! F_76 )
return - V_78 ;
return F_76 ( V_12 , V_74 , V_70 , V_71 , V_9 , V_13 ) ;
}
