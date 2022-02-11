unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
void F_3 ( unsigned int V_1 , unsigned int V_3 )
{
F_4 ( V_2 + V_1 , V_3 ) ;
}
unsigned int F_5 ( int V_4 , unsigned int V_1 )
{
return F_2 ( V_5 [ V_4 ] + V_1 ) ;
}
void F_6 ( int V_4 , unsigned int V_1 , unsigned int V_3 )
{
F_4 ( V_5 [ V_4 ] + V_1 , V_3 ) ;
}
unsigned int F_7 ( unsigned int V_1 )
{
return F_2 ( V_6 + V_1 ) ;
}
void F_8 ( unsigned int V_1 , unsigned int V_3 )
{
F_4 ( V_6 + V_1 , V_3 ) ;
}
static int F_9 ( enum V_7 type )
{
int V_8 ;
int V_9 , V_10 ;
switch ( type & ( V_11 | V_12 ) ) {
case V_11 :
V_9 = 0 ;
V_10 = 10 ;
break;
case V_12 :
V_9 = 10 ;
V_10 = V_13 ;
break;
default:
V_9 = 0 ;
V_10 = V_13 ;
break;
}
V_14:
V_8 = F_10 ( V_15 , V_13 , V_9 ) ;
if ( V_8 >= V_10 )
return - V_16 ;
if ( ! F_11 ( V_8 , V_15 ) )
goto V_14;
return V_8 ;
}
static void F_12 ( int V_17 )
{
F_13 ( F_14 ( V_17 , V_15 ) ) ;
F_15 ( V_17 , V_15 ) ;
}
static int F_16 ( void )
{
int V_8 ;
V_14:
V_8 = F_17 ( V_18 , V_19 ) ;
if ( V_8 >= V_13 )
return - V_16 ;
if ( ! F_11 ( V_8 , V_18 ) )
goto V_14;
return V_8 ;
}
static void F_18 ( int V_17 )
{
F_13 ( F_14 ( V_17 , V_18 ) ) ;
F_15 ( V_17 , V_18 ) ;
}
void * F_19 ( enum V_7 type ,
int V_20 , int V_21 )
{
void * V_22 ;
struct V_23 * V_17 ;
int V_24 ;
F_13 ( V_20 < sizeof( struct V_23 ) ) ;
V_22 = F_20 ( V_20 , V_25 ) ;
if ( ! V_22 )
return NULL ;
V_17 = V_22 + V_21 ;
V_17 -> V_26 = V_22 ;
switch ( type & ( V_27 | V_28 ) ) {
case V_28 :
V_24 = F_16 () ;
V_17 -> V_24 = V_24 ;
V_17 -> V_29 = F_21 ( NULL ,
V_30 + V_31 + V_24 ) ;
V_17 -> V_32 = & V_33 -> V_34 [ V_24 ] ;
break;
case V_27 :
V_24 = F_9 ( type ) ;
V_17 -> V_24 = V_24 ;
V_17 -> V_29 = F_21 ( NULL , V_30 + V_24 ) ;
V_17 -> V_32 = & V_33 -> V_35 [ V_24 ] ;
break;
}
V_17 -> V_36 = type ;
return V_17 ;
}
void F_22 ( struct V_23 * V_17 )
{
if ( V_17 -> V_37 )
F_23 ( V_17 ) ;
switch ( V_17 -> V_36 & ( V_28 | V_27 ) ) {
case V_28 :
F_18 ( V_17 -> V_24 ) ;
break;
case V_27 :
F_12 ( V_17 -> V_24 ) ;
break;
}
F_24 ( V_17 -> V_26 ) ;
}
int F_25 ( struct V_23 * V_17 , int V_38 )
{
F_13 ( V_17 -> V_37 ) ;
V_17 -> V_38 = V_38 ;
V_17 -> V_37 = F_26 ( & V_39 -> V_40 ,
V_38 * sizeof( V_41 ) ,
& V_17 -> V_42 , V_25 ) ;
if ( ! V_17 -> V_37 )
return - V_43 ;
memset ( V_17 -> V_37 , 0 , V_38 * sizeof( V_41 ) ) ;
return 0 ;
}
void F_23 ( struct V_23 * V_17 )
{
F_13 ( ! V_17 -> V_37 ) ;
F_27 ( & V_39 -> V_40 , V_17 -> V_38 * sizeof( V_41 ) ,
V_17 -> V_37 , V_17 -> V_42 ) ;
V_17 -> V_37 = NULL ;
V_17 -> V_38 = 0 ;
V_17 -> V_42 = 0 ;
}
void F_28 ( const struct V_23 * V_17 , const T_1 V_44 )
{
if ( V_17 -> V_36 == V_28 )
F_8 ( F_29 ( V_17 -> V_24 ) ,
V_44 | V_45 ) ;
else
F_8 ( F_30 ( V_17 -> V_24 ) ,
V_44 | V_46 ) ;
}
int F_31 ( const struct V_23 * V_17 )
{
int V_1 , V_47 ;
T_1 V_48 ;
if ( V_17 -> V_36 == V_28 ) {
V_1 = F_29 ( V_17 -> V_24 ) ;
F_8 ( V_1 , V_49 ) ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_48 = F_7 ( V_1 ) ;
if ( ! ( V_48 & V_51 ) ) {
F_8 ( V_1 , 0 ) ;
return 1 ;
}
F_32 () ;
}
} else {
V_1 = F_30 ( V_17 -> V_24 ) ;
F_8 ( V_1 , V_52 ) ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_48 = F_7 ( V_1 ) ;
if ( ! ( V_48 & V_53 ) ) {
F_8 ( V_1 , 0 ) ;
return 1 ;
}
F_32 () ;
}
}
return 0 ;
}
void * F_33 ( struct V_23 * V_17 , int V_54 ,
T_2 * V_55 )
{
return F_26 ( & V_39 -> V_40 , V_54 , V_55 , V_25 ) ;
}
void F_34 ( struct V_23 * V_17 , int V_54 ,
T_2 * V_55 )
{
F_27 ( & V_39 -> V_40 , V_54 , V_55 , V_25 ) ;
}
int F_35 ( void )
{
int V_8 ;
V_14:
V_8 = F_10 ( V_56 , V_57 , 0 ) ;
if ( V_8 >= V_57 )
return - V_16 ;
if ( ! F_11 ( V_8 , V_56 ) )
goto V_14;
return V_8 ;
}
void F_36 ( int V_58 )
{
F_13 ( F_14 ( V_58 , V_56 ) ) ;
F_13 ( V_58 >= V_57 ) ;
F_15 ( V_58 , V_56 ) ;
}
void F_37 ( int V_58 )
{
F_13 ( V_58 >= V_57 ) ;
if ( V_58 < 32 )
F_8 ( V_59 , 1 << V_58 ) ;
else
F_8 ( V_60 , 1 << V_58 ) ;
}
void F_38 ( int V_58 )
{
F_13 ( V_58 >= V_57 ) ;
if ( V_58 < 32 )
F_8 ( V_61 , 1 << V_58 ) ;
else
F_8 ( V_62 , 1 << V_58 ) ;
}
int F_39 ( void )
{
int V_8 ;
V_14:
V_8 = F_10 ( V_63 , V_57 , 0 ) ;
if ( V_8 >= V_57 )
return - V_16 ;
if ( ! F_11 ( V_8 , V_63 ) )
goto V_14;
return V_8 ;
}
void F_40 ( int V_64 )
{
F_13 ( F_14 ( V_64 , V_63 ) ) ;
F_13 ( V_64 >= V_57 ) ;
F_15 ( V_64 , V_63 ) ;
}
static void * F_41 ( struct V_65 * V_66 , int V_67 )
{
struct V_68 * V_69 ;
void T_3 * V_70 ;
V_69 = F_42 ( V_66 ) ;
if ( ! V_69 )
goto V_71;
V_70 = F_43 ( V_69 , V_67 ) ;
if ( ! V_70 )
goto V_71;
return V_70 ;
V_71:
return F_44 ( 0xe0000000 + ( V_66 -> V_72 << 12 ) , 0x2000 ) ;
}
int F_45 ( void )
{
static F_46 ( V_73 ) ;
struct V_65 * V_74 ;
struct V_65 * V_75 ;
struct V_76 V_77 ;
struct V_68 * V_69 ;
int V_78 , V_4 , V_79 = 0 ;
unsigned long V_80 ;
T_1 V_81 ;
if ( ! F_47 ( V_82 ) )
return - V_83 ;
F_48 ( & V_73 ) ;
if ( V_39 )
goto V_84;
V_74 = F_49 ( V_85 , 0xa001 , NULL ) ;
if ( ! V_74 ) {
F_50 () ;
F_51 ( V_86 L_1 ) ;
V_79 = - V_83 ;
goto V_84;
}
V_2 = F_41 ( V_74 , 0 ) ;
V_39 = F_49 ( V_85 , 0xa007 , NULL ) ;
if ( ! V_39 ) {
F_50 () ;
F_51 ( V_86 L_2 ) ;
V_79 = - V_83 ;
goto V_84;
}
V_6 = F_41 ( V_39 , 0 ) ;
V_30 = F_52 ( V_39 -> V_29 ) ;
F_53 ( V_39 , V_87 , & V_81 ) ;
V_31 = ( V_81 & V_88 ) >> V_89 ;
F_53 ( V_39 , V_90 , & V_81 ) ;
V_91 = ( V_81 & V_92 ) >> V_93 ;
V_4 = 0 ;
for ( V_75 = F_49 ( V_85 , 0xa006 , NULL ) ;
V_75 ;
V_75 = F_49 ( V_85 , 0xa006 , V_75 ) )
V_5 [ V_4 ++ ] = F_41 ( V_75 , 0 ) ;
F_54 ( V_75 ) ;
for ( V_75 = F_49 ( V_85 , 0xa005 , NULL ) ;
V_75 ;
V_75 = F_49 ( V_85 , 0xa005 , V_75 ) )
V_5 [ V_4 ++ ] = F_41 ( V_75 , 0 ) ;
F_54 ( V_75 ) ;
V_69 = F_42 ( V_74 ) ;
if ( V_69 )
V_79 = F_55 ( V_69 , 1 , & V_77 ) ;
if ( ! V_69 || V_79 ) {
V_77 . V_9 = 0xfd800000 ;
V_77 . V_94 = V_77 . V_9 + 0x1000 ;
}
V_33 = F_56 ( V_77 . V_9 , V_77 . V_94 - V_77 . V_9 , 0 ) ;
F_54 ( V_74 ) ;
for ( V_78 = 0 ; V_78 < V_13 ; V_78 ++ )
F_57 ( V_78 , V_15 ) ;
for ( V_78 = 0 ; V_78 < V_19 ; V_78 ++ )
F_57 ( V_78 , V_18 ) ;
V_80 = V_95 + V_96 ;
F_8 ( V_97 , 0 ) ;
while ( F_7 ( V_98 ) & 1 ) {
if ( F_58 ( V_95 , V_80 ) ) {
F_59 ( L_3 ) ;
break;
}
}
V_80 = V_95 + V_96 ;
F_8 ( V_99 , 0 ) ;
while ( F_7 ( V_100 ) & 1 ) {
if ( F_58 ( V_95 , V_80 ) ) {
F_59 ( L_4 ) ;
break;
}
}
V_81 = F_7 ( V_101 ) ;
F_8 ( V_101 , V_81 | 0x18000000 ) ;
F_8 ( V_99 , V_102 ) ;
F_8 ( V_97 , V_103 ) ;
for ( V_78 = 0 ; V_78 < V_57 ; V_78 ++ )
F_57 ( V_78 , V_56 ) ;
for ( V_78 = 0 ; V_78 < V_104 ; V_78 ++ )
F_57 ( V_78 , V_63 ) ;
F_8 ( V_61 , 0xffffffff ) ;
F_8 ( V_62 , 0xffffffff ) ;
F_51 ( V_105 L_5
L_6 , V_31 , V_91 ) ;
V_84:
F_60 ( & V_73 ) ;
return V_79 ;
}
