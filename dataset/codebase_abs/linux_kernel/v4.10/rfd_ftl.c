static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = & V_2 -> V_5 [ V_3 ] ;
int V_6 ;
V_4 -> V_7 = V_2 -> V_8 * V_3 ;
if ( F_2 ( V_2 -> V_9 [ 0 ] ) != V_10 ) {
V_4 -> V_11 = V_12 ;
return - V_13 ;
}
V_4 -> V_11 = V_14 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_15 ; V_6 ++ ) {
T_1 V_16 ;
V_16 = F_2 ( V_2 -> V_9 [ V_17 + V_6 ] ) ;
if ( V_16 == V_18 )
continue;
if ( V_16 == V_19 ) {
V_4 -> V_20 ++ ;
continue;
}
if ( V_16 == V_21 )
V_16 = 0 ;
if ( V_16 >= V_2 -> V_22 ) {
F_3 (KERN_WARNING PREFIX
L_1
L_2 ,
part->mbd.mtd->name, block_no, i, entry) ;
continue;
}
if ( V_2 -> V_23 [ V_16 ] != - 1 ) {
F_3 (KERN_WARNING PREFIX
L_3 ,
part->mbd.mtd->name, entry) ;
V_2 -> V_24 = 1 ;
continue;
}
V_2 -> V_23 [ V_16 ] = V_4 -> V_7 +
( V_6 + V_2 -> V_25 ) * V_26 ;
V_4 -> V_27 ++ ;
}
if ( V_4 -> V_20 == V_2 -> V_15 )
V_2 -> V_28 = V_3 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_29 ;
int V_6 , V_30 = - V_31 ;
int V_32 ;
T_2 V_33 ;
V_29 = V_2 -> V_8 / V_26 ;
V_2 -> V_34 = ( V_35 ) V_2 -> V_36 . V_37 -> V_38 / V_2 -> V_8 ;
if ( V_2 -> V_34 < 2 )
return - V_13 ;
V_2 -> V_25 =
( ( V_17 + V_29 ) *
sizeof( T_1 ) + V_26 - 1 ) / V_26 ;
V_2 -> V_15 = V_29 -
V_2 -> V_25 ;
V_2 -> V_39 = ( V_17 +
V_2 -> V_15 ) * sizeof( T_1 ) ;
V_2 -> V_40 = ( V_2 -> V_15 *
( V_2 -> V_34 - 1 ) - 1 ) / V_41 ;
V_2 -> V_22 = V_2 -> V_40 * V_41 ;
V_2 -> V_42 = - 1 ;
V_2 -> V_28 = - 1 ;
V_2 -> V_43 = 0 ;
V_2 -> V_9 = F_5 ( V_2 -> V_39 , V_44 ) ;
if ( ! V_2 -> V_9 )
goto V_45;
V_2 -> V_5 = F_6 ( V_2 -> V_34 , sizeof( struct V_4 ) ,
V_44 ) ;
if ( ! V_2 -> V_5 )
goto V_45;
V_2 -> V_23 = F_7 ( V_2 -> V_22 * sizeof( V_46 ) ) ;
if ( ! V_2 -> V_23 ) {
F_3 (KERN_ERR PREFIX L_4
L_5 , part->mbd.mtd->name) ;
goto V_45;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_22 ; V_6 ++ )
V_2 -> V_23 [ V_6 ] = - 1 ;
for ( V_6 = 0 , V_32 = 0 ; V_6 < V_2 -> V_34 ; V_6 ++ ) {
V_30 = F_8 ( V_2 -> V_36 . V_37 , V_6 * V_2 -> V_8 ,
V_2 -> V_39 , & V_33 ,
( V_47 * ) V_2 -> V_9 ) ;
if ( ! V_30 && V_33 != V_2 -> V_39 )
V_30 = - V_48 ;
if ( V_30 )
goto V_45;
if ( ! F_1 ( V_2 , V_6 ) )
V_32 ++ ;
}
if ( V_32 == 0 ) {
F_3 (KERN_NOTICE PREFIX L_6 ,
part->mbd.mtd->name) ;
V_30 = - V_13 ;
goto V_45;
}
if ( V_2 -> V_28 == - 1 ) {
F_3 (KERN_WARNING PREFIX L_7 ,
part->mbd.mtd->name) ;
V_2 -> V_24 = 1 ;
}
return 0 ;
V_45:
F_9 ( V_2 -> V_23 ) ;
F_10 ( V_2 -> V_9 ) ;
F_10 ( V_2 -> V_5 ) ;
return V_30 ;
}
static int F_11 ( struct V_49 * V_50 , V_46 V_51 , char * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
V_46 V_53 ;
T_2 V_33 ;
int V_30 ;
if ( V_51 >= V_2 -> V_22 )
return - V_48 ;
V_53 = V_2 -> V_23 [ V_51 ] ;
if ( V_53 != - 1 ) {
V_30 = F_8 ( V_2 -> V_36 . V_37 , V_53 , V_26 , & V_33 ,
( V_47 * ) V_52 ) ;
if ( ! V_30 && V_33 != V_26 )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_WARNING PREFIX L_8
L_9 , part->mbd.mtd->name, addr) ;
return V_30 ;
}
} else
memset ( V_52 , 0 , V_26 ) ;
return 0 ;
}
static void F_12 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
T_1 V_56 ;
int V_6 , V_30 ;
T_2 V_33 ;
V_2 = (struct V_1 * ) V_55 -> V_57 ;
V_6 = ( V_35 ) V_55 -> V_53 / V_2 -> V_8 ;
if ( V_6 >= V_2 -> V_34 || V_2 -> V_5 [ V_6 ] . V_7 != V_55 -> V_53 ||
V_55 -> V_53 > V_58 ) {
F_3 (KERN_ERR PREFIX L_10
L_11 , (unsigned long long)erase->addr, part->mbd.mtd->name) ;
return;
}
if ( V_55 -> V_11 != V_59 ) {
F_3 (KERN_WARNING PREFIX L_12
L_13 , (unsigned long long)erase->addr,
part->mbd.mtd->name, erase->state) ;
V_2 -> V_5 [ V_6 ] . V_11 = V_60 ;
V_2 -> V_5 [ V_6 ] . V_20 = 0 ;
V_2 -> V_5 [ V_6 ] . V_27 = 0 ;
F_10 ( V_55 ) ;
return;
}
V_56 = F_13 ( V_10 ) ;
V_2 -> V_5 [ V_6 ] . V_11 = V_61 ;
V_2 -> V_5 [ V_6 ] . V_20 = V_2 -> V_15 ;
V_2 -> V_5 [ V_6 ] . V_27 = 0 ;
V_2 -> V_5 [ V_6 ] . V_62 ++ ;
V_30 = F_14 ( V_2 -> V_36 . V_37 , V_2 -> V_5 [ V_6 ] . V_7 , sizeof( V_56 ) ,
& V_33 , ( V_47 * ) & V_56 ) ;
if ( ! V_30 && V_33 != sizeof( V_56 ) )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_14
L_15 ,
part->mbd.mtd->name,
part->blocks[i].offset) ;
V_2 -> V_5 [ V_6 ] . V_11 = V_60 ;
}
else
V_2 -> V_5 [ V_6 ] . V_11 = V_14 ;
F_10 ( V_55 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_4 )
{
struct V_54 * V_55 ;
int V_30 = - V_31 ;
V_55 = F_5 ( sizeof( struct V_54 ) , V_44 ) ;
if ( ! V_55 )
goto V_45;
V_55 -> V_37 = V_2 -> V_36 . V_37 ;
V_55 -> V_63 = F_12 ;
V_55 -> V_53 = V_2 -> V_5 [ V_4 ] . V_7 ;
V_55 -> V_64 = V_2 -> V_8 ;
V_55 -> V_57 = ( V_46 ) V_2 ;
V_2 -> V_5 [ V_4 ] . V_11 = V_65 ;
V_2 -> V_5 [ V_4 ] . V_20 = 0 ;
V_30 = F_16 ( V_2 -> V_36 . V_37 , V_55 ) ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_16
L_17 , (unsigned long long)erase->addr,
(unsigned long long)erase->len, part->mbd.mtd->name) ;
F_10 ( V_55 ) ;
}
V_45:
return V_30 ;
}
static int F_17 ( struct V_1 * V_2 , int V_3 , V_46 * V_66 )
{
void * V_67 ;
T_1 * V_68 ;
T_2 V_33 ;
int V_6 , V_30 = - V_31 ;
V_2 -> V_43 = 1 ;
V_67 = F_5 ( V_26 , V_44 ) ;
if ( ! V_67 )
goto V_69;
V_68 = F_5 ( V_2 -> V_39 , V_44 ) ;
if ( ! V_68 )
goto V_70;
V_30 = F_8 ( V_2 -> V_36 . V_37 , V_2 -> V_5 [ V_3 ] . V_7 ,
V_2 -> V_39 , & V_33 , ( V_47 * ) V_68 ) ;
if ( ! V_30 && V_33 != V_2 -> V_39 )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_8
L_9 , part->mbd.mtd->name,
part->blocks[block_no].offset) ;
goto V_45;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_15 ; V_6 ++ ) {
T_1 V_16 = F_2 ( V_68 [ V_17 + V_6 ] ) ;
V_46 V_53 ;
if ( V_16 == V_19 || V_16 == V_18 )
continue;
if ( V_16 == V_21 )
V_16 = 0 ;
if ( V_16 >= V_2 -> V_22 )
continue;
V_53 = V_2 -> V_5 [ V_3 ] . V_7 +
( V_6 + V_2 -> V_25 ) * V_26 ;
if ( * V_66 == V_53 ) {
* V_66 = - 1 ;
if ( ! V_2 -> V_5 [ V_3 ] . V_27 -- ) {
V_30 = F_15 ( V_2 , V_3 ) ;
break;
}
continue;
}
V_30 = F_8 ( V_2 -> V_36 . V_37 , V_53 , V_26 , & V_33 ,
V_67 ) ;
if ( ! V_30 && V_33 != V_26 )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_18
L_19 ,
part->mbd.mtd->name) ;
goto V_45;
}
V_30 = F_18 ( (struct V_49 * ) V_2 ,
V_16 , V_67 ) ;
if ( V_30 )
goto V_45;
}
V_45:
F_10 ( V_68 ) ;
V_70:
F_10 ( V_67 ) ;
V_69:
V_2 -> V_43 = 0 ;
return V_30 ;
}
static int F_19 ( struct V_1 * V_2 , V_46 * V_66 )
{
int V_4 , V_71 , V_72 , V_73 ;
int V_30 ;
F_20 ( V_2 -> V_36 . V_37 ) ;
V_72 = 0x7fffffff ;
V_71 = - 1 ;
if ( * V_66 != - 1 )
V_73 = * V_66 / V_2 -> V_8 ;
else
V_73 = - 1 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_34 ; V_4 ++ ) {
int V_74 ;
if ( V_4 == V_2 -> V_28 )
continue;
if ( V_2 -> V_5 [ V_4 ] . V_20 )
return 0 ;
V_74 = V_2 -> V_5 [ V_4 ] . V_27 ;
if ( V_4 == V_73 )
V_74 -- ;
else {
if ( V_2 -> V_5 [ V_4 ] . V_27 ==
V_2 -> V_15 )
continue;
}
V_74 += V_2 -> V_5 [ V_4 ] . V_62 ;
if ( V_74 < V_72 ) {
V_71 = V_4 ;
V_72 = V_74 ;
}
}
if ( V_71 == - 1 )
return - V_75 ;
V_2 -> V_42 = - 1 ;
V_2 -> V_28 = V_71 ;
F_21 ( L_20
L_21 , V_71 ,
V_2 -> V_5 [ V_71 ] . V_27 ,
V_2 -> V_5 [ V_71 ] . V_20 ) ;
if ( V_2 -> V_5 [ V_71 ] . V_27 )
V_30 = F_17 ( V_2 , V_71 , V_66 ) ;
else
V_30 = F_15 ( V_2 , V_71 ) ;
return V_30 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_4 , V_76 ;
V_4 = V_2 -> V_42 == - 1 ?
V_77 % V_2 -> V_34 : V_2 -> V_42 ;
V_76 = V_4 ;
do {
if ( V_2 -> V_5 [ V_4 ] . V_20 &&
V_4 != V_2 -> V_28 )
return V_4 ;
if ( V_2 -> V_5 [ V_4 ] . V_11 == V_12 )
F_15 ( V_2 , V_4 ) ;
if ( ++ V_4 >= V_2 -> V_34 )
V_4 = 0 ;
} while ( V_4 != V_76 );
return - 1 ;
}
static int F_23 ( struct V_1 * V_2 , V_46 * V_66 )
{
int V_30 , V_4 ;
T_2 V_33 ;
V_4 = F_22 ( V_2 ) ;
if ( V_4 == - 1 ) {
if ( ! V_2 -> V_43 ) {
V_30 = F_19 ( V_2 , V_66 ) ;
if ( V_30 )
goto V_45;
V_4 = F_22 ( V_2 ) ;
}
if ( V_4 == - 1 ) {
V_30 = - V_75 ;
goto V_45;
}
}
V_30 = F_8 ( V_2 -> V_36 . V_37 , V_2 -> V_5 [ V_4 ] . V_7 ,
V_2 -> V_39 , & V_33 ,
( V_47 * ) V_2 -> V_9 ) ;
if ( ! V_30 && V_33 != V_2 -> V_39 )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_22
L_9 , part->mbd.mtd->name,
part->blocks[block].offset) ;
goto V_45;
}
V_2 -> V_42 = V_4 ;
V_45:
return V_30 ;
}
static int F_24 ( struct V_1 * V_2 , V_46 V_78 )
{
int V_4 , V_7 , V_30 ;
V_46 V_53 ;
T_2 V_33 ;
T_1 V_79 = F_13 ( V_18 ) ;
V_4 = V_78 / V_2 -> V_8 ;
V_7 = ( V_78 % V_2 -> V_8 ) / V_26 -
V_2 -> V_25 ;
V_53 = V_2 -> V_5 [ V_4 ] . V_7 +
( V_17 + V_7 ) * sizeof( T_1 ) ;
V_30 = F_14 ( V_2 -> V_36 . V_37 , V_53 , sizeof( V_79 ) , & V_33 ,
( V_47 * ) & V_79 ) ;
if ( ! V_30 && V_33 != sizeof( V_79 ) )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_23
L_9 , part->mbd.mtd->name, addr) ;
goto V_45;
}
if ( V_4 == V_2 -> V_42 )
V_2 -> V_9 [ V_7 + V_17 ] = V_79 ;
V_2 -> V_5 [ V_4 ] . V_27 -- ;
if ( ! V_2 -> V_5 [ V_4 ] . V_27 &&
! V_2 -> V_5 [ V_4 ] . V_20 )
V_30 = F_15 ( V_2 , V_4 ) ;
V_45:
return V_30 ;
}
static int F_25 ( const struct V_1 * V_2 , const struct V_4 * V_4 )
{
int V_6 , V_76 ;
V_6 = V_76 = V_2 -> V_15 - V_4 -> V_20 ;
do {
if ( F_2 ( V_2 -> V_9 [ V_17 + V_6 ] )
== V_19 )
return V_6 ;
if ( ++ V_6 == V_2 -> V_15 )
V_6 = 0 ;
}
while( V_6 != V_76 );
return - 1 ;
}
static int F_26 ( struct V_49 * V_50 , V_46 V_51 , char * V_52 , T_3 * V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
struct V_4 * V_4 ;
V_46 V_53 ;
int V_6 ;
int V_30 ;
T_2 V_33 ;
T_1 V_16 ;
if ( V_2 -> V_42 == - 1 ||
! V_2 -> V_5 [ V_2 -> V_42 ] . V_20 ) {
V_30 = F_23 ( V_2 , V_78 ) ;
if ( V_30 )
goto V_45;
}
V_4 = & V_2 -> V_5 [ V_2 -> V_42 ] ;
V_6 = F_25 ( V_2 , V_4 ) ;
if ( V_6 < 0 ) {
V_30 = - V_75 ;
goto V_45;
}
V_53 = ( V_6 + V_2 -> V_25 ) * V_26 +
V_4 -> V_7 ;
V_30 = F_14 ( V_2 -> V_36 . V_37 , V_53 , V_26 , & V_33 ,
( V_47 * ) V_52 ) ;
if ( ! V_30 && V_33 != V_26 )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_24 ,
part->mbd.mtd->name, addr) ;
goto V_45;
}
V_2 -> V_23 [ V_51 ] = V_53 ;
V_16 = F_13 ( V_51 == 0 ? V_21 : V_51 ) ;
V_2 -> V_9 [ V_6 + V_17 ] = V_16 ;
V_53 = V_4 -> V_7 + ( V_17 + V_6 ) * sizeof( T_1 ) ;
V_30 = F_14 ( V_2 -> V_36 . V_37 , V_53 , sizeof( V_16 ) , & V_33 ,
( V_47 * ) & V_16 ) ;
if ( ! V_30 && V_33 != sizeof( V_16 ) )
V_30 = - V_48 ;
if ( V_30 ) {
F_3 (KERN_ERR PREFIX L_24 ,
part->mbd.mtd->name, addr) ;
goto V_45;
}
V_4 -> V_27 ++ ;
V_4 -> V_20 -- ;
V_45:
return V_30 ;
}
static int F_18 ( struct V_49 * V_50 , V_46 V_51 , char * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
V_46 V_78 ;
int V_6 ;
int V_30 = 0 ;
F_21 ( L_25 , V_51 ) ;
if ( V_2 -> V_28 == - 1 ) {
V_30 = - V_80 ;
goto V_45;
}
if ( V_51 >= V_2 -> V_22 ) {
V_30 = - V_48 ;
goto V_45;
}
V_78 = V_2 -> V_23 [ V_51 ] ;
for ( V_6 = 0 ; V_6 < V_26 ; V_6 ++ ) {
if ( ! V_52 [ V_6 ] )
continue;
V_30 = F_26 ( V_50 , V_51 , V_52 , & V_78 ) ;
if ( V_30 )
goto V_45;
break;
}
if ( V_6 == V_26 )
V_2 -> V_23 [ V_51 ] = - 1 ;
if ( V_78 != - 1 )
V_30 = F_24 ( V_2 , V_78 ) ;
V_45:
return V_30 ;
}
static int F_27 ( struct V_49 * V_50 , struct V_81 * V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
V_82 -> V_83 = 1 ;
V_82 -> V_84 = V_41 ;
V_82 -> V_40 = V_2 -> V_40 ;
return 0 ;
}
static void F_28 ( struct V_85 * V_86 , struct V_87 * V_37 )
{
struct V_1 * V_2 ;
if ( V_37 -> type != V_88 || V_37 -> V_38 > V_58 )
return;
V_2 = F_29 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_2 )
return;
V_2 -> V_36 . V_37 = V_37 ;
if ( V_8 )
V_2 -> V_8 = V_8 ;
else {
if ( ! V_37 -> V_89 ) {
F_3 (KERN_WARNING PREFIX L_26 ) ;
goto V_90;
} else
V_2 -> V_8 = V_37 -> V_89 ;
}
if ( F_4 ( V_2 ) == 0 ) {
V_2 -> V_36 . V_38 = V_2 -> V_22 ;
V_2 -> V_36 . V_86 = V_86 ;
V_2 -> V_36 . V_91 = - 1 ;
if ( ! ( V_37 -> V_92 & V_93 ) )
V_2 -> V_36 . V_94 = 1 ;
else if ( V_2 -> V_24 ) {
F_3 (KERN_WARNING PREFIX L_27
L_28 , mtd->name) ;
V_2 -> V_36 . V_94 = 1 ;
}
F_3 (KERN_INFO PREFIX L_29 ,
mtd->name, mtd->type, mtd->flags) ;
if ( ! F_30 ( ( void * ) V_2 ) )
return;
}
V_90:
F_10 ( V_2 ) ;
}
static void F_31 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_34 ; V_6 ++ ) {
F_21 ( L_30 ,
V_2 -> V_36 . V_37 -> V_95 , V_6 , V_2 -> V_5 [ V_6 ] . V_62 ) ;
}
F_32 ( V_50 ) ;
F_9 ( V_2 -> V_23 ) ;
F_10 ( V_2 -> V_9 ) ;
F_10 ( V_2 -> V_5 ) ;
}
static int T_4 F_33 ( void )
{
return F_34 ( & V_96 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_96 ) ;
}
