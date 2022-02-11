static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( T_1 V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
F_5 ( V_9 ) ;
int V_10 ;
V_10 = F_6 ( & V_8 , V_11 , 1 ,
V_12 , & V_9 , V_5 ) ;
if ( V_10 )
return V_10 ;
F_7 ( & V_9 ) ;
if ( V_8 . V_8 . V_13 != 0 )
return V_8 . V_8 . V_13 ;
if ( V_8 . V_8 . V_14 != 2 ) {
F_8 ( V_15 L_1 ,
V_5 , V_8 . V_8 . V_14 ) ;
return - V_16 ;
}
* V_6 = * ( ( V_17 * ) V_8 . V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
T_2 V_19 ;
T_3 V_20 ;
V_10 = F_4 ( V_4 -> V_21 , & V_19 ) ;
if ( V_10 ) {
F_8 ( V_15 L_2 ,
V_10 ) ;
return V_10 ;
}
V_20 = ( T_3 ) ( ( ( V_22 ) V_19 ) * ( V_22 ) V_23 -> V_24 ) ;
V_20 >>= 3 ;
V_20 += ( ( T_3 ) V_23 -> V_25 ) << 9 ;
* V_6 = ( T_2 ) ( V_20 << 1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_19 , V_20 ;
int V_10 ;
V_10 = F_4 ( V_4 -> V_21 , & V_19 ) ;
if ( V_10 ) {
F_8 ( V_15 L_3 ,
V_10 ) ;
return V_10 ;
}
V_20 = ( T_2 ) ( V_19 * ( V_26 ) V_27 -> V_28 ) ;
V_20 += ( T_2 ) V_27 -> V_29 ;
* V_6 = V_20 << 4 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_19 , V_20 ;
int V_10 ;
V_10 = F_4 ( V_4 -> V_21 , & V_19 ) ;
if ( V_10 ) {
F_8 ( V_15 L_4 ,
V_10 ) ;
return V_10 ;
}
V_20 = ( T_2 ) ( V_19 * ( V_26 ) V_27 -> V_30 ) ;
V_20 += ( T_2 ) V_27 -> V_31 ;
* V_6 = V_20 << 4 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_19 , V_20 ;
int V_10 ;
V_10 = F_4 ( V_4 -> V_21 , & V_19 ) ;
if ( V_10 ) {
F_8 ( V_15 L_5 ,
V_10 ) ;
return V_10 ;
}
V_20 = ( T_2 ) ( V_19 * ( V_26 ) V_32 -> V_33 ) ;
V_20 += ( T_2 ) V_32 -> V_34 ;
* V_6 = V_20 << 4 ;
return 0 ;
}
static struct V_3 * F_13 ( struct V_35 * V_36 )
{
struct V_3 * V_4 ;
const char * V_37 , * V_38 ;
const V_26 * V_39 ;
V_4 = F_14 ( sizeof( struct V_3 ) , V_40 ) ;
if ( V_4 == NULL )
return NULL ;
V_37 = F_15 ( V_36 , L_6 , NULL ) ;
V_38 = F_15 ( V_36 , L_7 , NULL ) ;
if ( V_37 == NULL || V_38 == NULL )
goto V_41;
if ( ! strcmp ( V_37 , L_8 ) &&
! strcmp ( V_38 , L_9 ) ) {
V_4 -> V_42 . V_43 = & V_44 ;
V_4 -> V_42 . V_45 = L_10 ;
if ( V_23 == NULL ) {
F_16 ( L_11 ,
V_46 ) ;
goto V_41;
}
} else if ( ! strcmp ( V_37 , L_12 ) &&
! strcmp ( V_38 , L_13 ) ) {
V_4 -> V_42 . V_43 = & V_47 ;
V_4 -> V_42 . V_45 = L_14 ;
if ( V_27 == NULL ) {
F_16 ( L_15 ,
V_48 ) ;
goto V_41;
}
} else if ( ! strcmp ( V_37 , L_16 ) &&
! strcmp ( V_38 , L_17 ) ) {
V_4 -> V_42 . V_43 = & V_49 ;
V_4 -> V_42 . V_45 = L_18 ;
if ( V_27 == NULL ) {
F_16 ( L_15 ,
V_48 ) ;
goto V_41;
}
} else if ( ! strcmp ( V_37 , L_19 ) &&
! strcmp ( V_38 , L_20 ) ) {
V_4 -> V_42 . V_43 = & V_50 ;
V_4 -> V_42 . V_45 = L_21 ;
if ( V_32 == NULL ) {
F_16 ( L_22 ,
V_51 ) ;
goto V_41;
}
} else
goto V_41;
V_39 = F_15 ( V_36 , L_23 , NULL ) ;
if ( V_39 == NULL )
goto V_41;
V_4 -> V_21 = * V_39 ;
if ( F_17 ( & V_4 -> V_42 ) )
goto V_41;
return V_4 ;
V_41:
F_3 ( V_4 ) ;
return NULL ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_52 * pow = F_19 ( V_2 ) ;
if ( pow -> V_53 )
F_20 ( pow -> V_53 ) ;
if ( pow -> V_54 )
F_20 ( pow -> V_54 ) ;
F_3 ( pow ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 * V_6 )
{
struct V_52 * pow = F_19 ( V_2 ) ;
T_2 V_53 , V_54 , V_55 ;
V_22 V_56 , V_57 , V_58 ;
int V_10 ;
V_10 = pow -> V_54 -> V_43 -> V_59 ( pow -> V_54 , & V_54 ) ;
if ( V_10 )
return V_10 ;
if ( pow -> V_60 ) {
* V_6 = V_54 * 12 - 0x30000 ;
return 0 ;
}
V_10 = pow -> V_53 -> V_43 -> V_59 ( pow -> V_53 , & V_53 ) ;
if ( V_10 )
return V_10 ;
V_55 = ( T_2 ) ( ( ( ( V_22 ) V_53 ) * ( ( V_22 ) V_54 ) ) >> 16 ) ;
if ( ! pow -> V_61 ) {
* V_6 = V_55 ;
return 0 ;
}
V_56 = ( ( ( V_22 ) V_55 ) * ( ( V_22 ) V_55 ) ) >> 16 ;
V_57 = ( ( V_22 ) V_27 -> V_62 [ 0 ] ) * V_56 ;
V_58 = ( ( V_22 ) V_27 -> V_62 [ 1 ] ) * ( ( V_22 ) V_55 ) ;
* V_6 = ( V_57 >> 28 ) + ( V_58 >> 28 ) + ( V_27 -> V_62 [ 2 ] >> 12 ) ;
return 0 ;
}
static struct V_52 *
F_22 ( struct V_1 * V_53 , struct V_1 * V_54 )
{
struct V_52 * pow ;
pow = F_14 ( sizeof( struct V_52 ) , V_40 ) ;
if ( pow == NULL )
return NULL ;
pow -> V_42 . V_43 = & V_63 ;
pow -> V_42 . V_45 = L_24 ;
F_23 ( V_53 ) ;
pow -> V_53 = V_53 ;
F_23 ( V_54 ) ;
pow -> V_54 = V_54 ;
if ( V_64 && ( ( * V_64 ) & 0x80 ) ) {
F_8 ( V_65 L_25
L_26 ) ;
pow -> V_60 = 1 ;
} else
pow -> V_60 = 0 ;
if ( ( F_24 ( L_27 ) ||
F_24 ( L_28 ) ||
F_24 ( L_29 ) ) &&
V_66 >= 2 ) {
pow -> V_61 = 1 ;
F_16 ( L_30 ) ;
} else
pow -> V_61 = 0 ;
if ( F_17 ( & pow -> V_42 ) )
goto V_41;
return pow ;
V_41:
F_3 ( pow ) ;
return NULL ;
}
static void F_25 ( void )
{
const struct V_67 * V_68 ;
V_68 = F_26 ( V_48 , NULL ) ;
if ( V_68 != NULL ) {
V_27 = (struct V_69 * ) & V_68 [ 1 ] ;
V_66 = V_68 -> V_70 ;
}
V_68 = F_26 ( V_46 , NULL ) ;
if ( V_68 != NULL )
V_23 = (struct V_71 * ) & V_68 [ 1 ] ;
V_68 = F_26 ( V_51 , NULL ) ;
if ( V_68 != NULL )
V_32 = (struct V_72 * ) & V_68 [ 1 ] ;
V_68 = F_26 ( V_73 , NULL ) ;
if ( V_68 != NULL )
V_64 = ( T_1 * ) & V_68 [ 1 ] ;
}
static int T_4 F_27 ( void )
{
struct V_35 * V_74 , * V_75 , * V_76 ;
struct V_3 * V_77 = NULL , * V_78 = NULL ;
if ( ! F_28 () )
return - V_79 ;
F_25 () ;
V_74 = F_29 ( NULL , L_31 ) ;
if ( V_74 == NULL )
return - V_79 ;
for ( V_75 = NULL ;
( V_75 = F_30 ( V_74 , V_75 ) ) != NULL ; )
if ( ! strcmp ( V_75 -> V_45 , L_32 ) )
break;
F_31 ( V_74 ) ;
for ( V_76 = NULL ;
V_75 && ( V_76 = F_30 ( V_75 , V_76 ) ) != NULL ; ) {
struct V_3 * V_4 ;
V_4 = F_13 ( V_76 ) ;
if ( V_4 == NULL )
continue;
F_32 ( & V_4 -> V_80 , & V_81 ) ;
if ( ! strcmp ( V_4 -> V_42 . V_45 , L_18 ) )
V_77 = V_4 ;
else if ( ! strcmp ( V_4 -> V_42 . V_45 , L_14 ) )
V_78 = V_4 ;
}
F_31 ( V_75 ) ;
if ( V_77 && V_78 )
V_82 = F_22 ( & V_77 -> V_42 ,
& V_78 -> V_42 ) ;
return 0 ;
}
static void T_5 F_33 ( void )
{
struct V_3 * V_4 ;
if ( V_82 )
F_34 ( & V_82 -> V_42 ) ;
while ( ! F_35 ( & V_81 ) ) {
V_4 = F_36 ( V_81 . V_83 , struct V_3 , V_80 ) ;
F_37 ( & V_4 -> V_80 ) ;
F_34 ( & V_4 -> V_42 ) ;
}
}
