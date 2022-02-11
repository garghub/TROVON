static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 ;
#ifdef F_2
V_5 = F_3 ( V_2 , V_4 ) ;
if ( ! V_5 ) {
F_4 ( V_2 , V_4 ) ;
return;
}
V_6 = V_4 -> V_7 ;
#else
struct V_8 * V_9 ;
F_5 ( F_6 ( V_10 L_1 ,
V_4 -> V_7 , V_4 -> V_7 , V_4 -> V_7 + V_2 -> V_11 ) ) ;
V_9 = F_7 ( sizeof( struct V_8 ) + sizeof( struct V_12 ) , V_13 ) ;
if ( ! V_9 ) {
F_6 ( V_14 L_2 ) ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_18 ) ;
V_2 -> V_19 -= V_2 -> V_11 ;
V_2 -> V_20 += V_2 -> V_11 ;
V_4 -> V_20 = V_2 -> V_11 ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
return;
}
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_21 = V_2 -> V_21 ;
V_9 -> V_22 = V_4 -> V_7 ;
V_9 -> V_23 = V_2 -> V_11 ;
V_9 -> V_24 = V_25 ;
V_9 -> V_26 = ( unsigned long ) ( & V_9 [ 1 ] ) ;
V_9 -> V_27 = V_28 ;
( (struct V_12 * ) V_9 -> V_26 ) -> V_4 = V_4 ;
( (struct V_12 * ) V_9 -> V_26 ) -> V_2 = V_2 ;
V_5 = F_13 ( V_2 -> V_21 , V_9 ) ;
if ( ! V_5 )
return;
V_6 = V_9 -> V_27 ;
F_14 ( V_9 ) ;
#endif
if ( V_5 == - V_29 || V_5 == - V_30 ) {
F_5 ( F_6 ( V_10 L_3 , V_4 -> V_7 , V_5 ) ) ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_18 ) ;
V_2 -> V_19 -= V_2 -> V_11 ;
V_2 -> V_20 += V_2 -> V_11 ;
V_4 -> V_20 = V_2 -> V_11 ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
return;
}
if ( V_5 == - V_31 )
F_6 ( V_14 L_4 , V_4 -> V_7 ) ;
else
F_6 ( V_14 L_5 , V_4 -> V_7 , V_5 ) ;
F_15 ( V_2 , V_4 , V_6 ) ;
}
int F_16 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 ;
int V_33 = 0 ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
while ( ! F_17 ( & V_2 -> V_34 ) ||
! F_17 ( & V_2 -> V_18 ) ) {
if ( ! F_17 ( & V_2 -> V_34 ) ) {
V_4 = F_18 ( V_2 -> V_34 . V_35 , struct V_3 , V_17 ) ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_36 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_19 ( V_2 , V_4 ) ;
V_33 ++ ;
if ( ! -- V_32 ) {
F_5 ( F_6 ( V_10 L_6 ) ) ;
goto V_37;
}
} else if ( ! F_17 ( & V_2 -> V_18 ) ) {
V_4 = F_18 ( V_2 -> V_18 . V_35 , struct V_3 , V_17 ) ;
F_5 ( F_6 ( V_10 L_7 , V_4 -> V_7 ) ) ;
F_20 ( & V_4 -> V_17 ) ;
V_2 -> V_19 += V_2 -> V_11 ;
V_2 -> V_38 -= V_4 -> V_38 ;
V_2 -> V_39 -= V_4 -> V_39 ;
V_2 -> V_40 -= V_4 -> V_40 ;
V_2 -> V_20 -= V_4 -> V_20 ;
V_4 -> V_38 = V_4 -> V_40 = V_4 -> V_20 = V_4 -> V_39 = 0 ;
F_21 ( V_2 , V_4 ) ;
F_22 ( & V_4 -> V_17 , & V_2 -> V_41 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_1 ( V_2 , V_4 ) ;
} else {
F_23 () ;
}
F_24 () ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
}
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
V_37:
F_5 ( F_6 ( V_10 L_8 ) ) ;
return V_33 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_5 ( F_6 ( V_10 L_9 , V_4 -> V_7 ) ) ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_25 ( & V_4 -> V_17 , & V_2 -> V_34 ) ;
F_26 ( V_2 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_27 ( & V_2 -> V_42 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_6 )
{
if ( F_28 ( V_2 ) && ( V_6 != ( T_1 ) V_28 ) ) {
if ( ! F_29 ( V_2 , V_4 , V_6 ) ) {
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_18 ) ;
V_2 -> V_19 -= V_2 -> V_11 ;
V_2 -> V_20 += V_2 -> V_11 ;
V_4 -> V_20 = V_2 -> V_11 ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
return;
}
}
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
V_2 -> V_19 -= V_2 -> V_11 ;
V_2 -> V_43 += V_2 -> V_11 ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_44 ) ;
V_2 -> V_45 -- ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_27 ( & V_2 -> V_42 ) ;
}
static void V_25 ( struct V_8 * V_9 )
{
struct V_12 * V_26 = ( void * ) V_9 -> V_26 ;
if( V_9 -> V_46 != V_47 ) {
F_6 ( V_14 L_10 ,
( unsigned long long ) V_9 -> V_22 , V_9 -> V_46 ) ;
F_15 ( V_26 -> V_2 , V_26 -> V_4 , V_9 -> V_27 ) ;
} else {
F_4 ( V_26 -> V_2 , V_26 -> V_4 ) ;
}
F_14 ( V_9 ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
struct V_48 * V_49 , struct V_3 * V_4 )
{
struct V_50 * V_51 = NULL ;
struct V_48 * * V_52 ;
V_52 = & V_49 -> V_53 ;
while ( 1 ) {
if ( ! ( * V_52 ) -> V_53 ) {
V_51 = (struct V_50 * ) ( * V_52 ) ;
V_52 = & V_51 -> V_54 ;
continue;
}
if ( F_31 ( ( * V_52 ) -> V_55 ) == V_4 -> V_7 ) {
struct V_48 * V_56 ;
V_56 = * V_52 ;
* V_52 = V_56 -> V_53 ;
V_56 -> V_53 = NULL ;
if ( V_56 == V_49 )
break;
continue;
}
V_52 = & ( ( * V_52 ) -> V_53 ) ;
}
if ( ! V_51 ) {
F_32 ( L_11
L_12 ) ;
return;
}
F_5 ( F_6 ( V_10 L_13 ,
V_4 -> V_7 , V_4 -> V_7 + V_2 -> V_11 , V_51 -> V_57 ) ) ;
F_33 ({
int i=0;
struct jffs2_raw_node_ref *this;
printk(KERN_DEBUG L_14);
this = ic->nodes;
printk(KERN_DEBUG);
while(this) {
printk(KERN_CONT L_15,
ref_offset(this), ref_flags(this));
if (++i == 5) {
printk(KERN_DEBUG);
i=0;
}
this = this->next_in_ino;
}
printk(KERN_CONT L_16);
}) ;
switch ( V_51 -> V_58 ) {
#ifdef F_34
case V_59 :
F_35 ( V_2 , (struct V_60 * ) V_51 ) ;
break;
case V_61 :
F_36 ( V_2 , (struct V_62 * ) V_51 ) ;
break;
#endif
default:
if ( V_51 -> V_54 == ( void * ) V_51 && V_51 -> V_63 == 0 )
F_37 ( V_2 , V_51 ) ;
}
}
void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_48 * V_64 , * V_49 ;
F_5 ( F_6 ( V_10 L_17 , V_4 -> V_7 ) ) ;
V_64 = V_49 = V_4 -> V_65 ;
while ( V_49 ) {
if ( V_49 -> V_55 == V_66 ) {
V_49 = V_49 -> V_53 ;
F_38 ( V_64 ) ;
V_64 = V_49 ;
continue;
}
if ( V_49 -> V_55 != V_67 && V_49 -> V_53 )
F_30 ( V_2 , V_49 , V_4 ) ;
V_49 ++ ;
}
V_4 -> V_65 = V_4 -> V_68 = NULL ;
}
static int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * V_6 )
{
void * V_69 ;
T_1 V_70 ;
T_2 V_71 ;
int V_5 ;
unsigned long * V_72 ;
V_5 = F_40 ( V_2 -> V_21 , V_4 -> V_7 , V_2 -> V_11 , & V_71 ,
& V_69 , NULL ) ;
if ( V_5 != - V_73 ) {
if ( V_5 ) {
F_5 ( F_6 ( V_10 L_18 , V_5 ) ) ;
goto V_74;
}
if ( V_71 < V_2 -> V_11 ) {
F_5 ( F_6 ( V_10 L_19 , V_71 ) ) ;
F_41 ( V_2 -> V_21 , V_4 -> V_7 , V_71 ) ;
goto V_74;
}
V_72 = V_69 - sizeof( * V_72 ) ;
V_71 /= sizeof( * V_72 ) ;
do {
if ( * ++ V_72 != ~ 0 )
break;
} while( -- V_71 );
F_41 ( V_2 -> V_21 , V_4 -> V_7 , V_2 -> V_11 ) ;
if ( V_71 ) {
F_6 ( V_14 L_20 ,
* V_72 , V_4 -> V_7 + V_2 -> V_11 - V_71 * sizeof( * V_72 ) ) ;
return - V_75 ;
}
return 0 ;
}
V_74:
V_69 = F_7 ( V_76 , V_13 ) ;
if ( ! V_69 ) {
F_6 ( V_14 L_21 , V_4 -> V_7 ) ;
return - V_30 ;
}
F_5 ( F_6 ( V_10 L_22 , V_4 -> V_7 ) ) ;
for ( V_70 = V_4 -> V_7 ; V_70 < V_4 -> V_7 + V_2 -> V_11 ; ) {
T_1 V_77 = F_42 ( ( T_1 ) V_76 , V_4 -> V_7 + V_2 -> V_11 - V_70 ) ;
int V_78 ;
* V_6 = V_70 ;
V_5 = F_43 ( V_2 -> V_21 , V_70 , V_77 , & V_71 , V_69 ) ;
if ( V_5 ) {
F_6 ( V_14 L_23 , V_70 , V_5 ) ;
V_5 = - V_75 ;
goto V_79;
}
if ( V_71 != V_77 ) {
F_6 ( V_14 L_24 , V_70 , V_77 , V_71 ) ;
V_5 = - V_75 ;
goto V_79;
}
for ( V_78 = 0 ; V_78 < V_77 ; V_78 += sizeof( unsigned long ) ) {
unsigned long * V_80 = V_69 + V_78 ;
if ( * V_80 + 1 ) {
* V_6 += V_78 ;
F_6 ( V_14 L_25 , * V_80 , * V_6 ) ;
V_5 = - V_75 ;
goto V_79;
}
}
V_70 += V_77 ;
F_24 () ;
}
V_5 = 0 ;
V_79:
F_14 ( V_69 ) ;
return V_5 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_71 ;
int V_5 ;
T_1 V_81 ( V_6 ) ;
switch ( F_39 ( V_2 , V_4 , & V_6 ) ) {
case - V_30 : goto V_82;
case - V_75 : goto V_83;
}
F_5 ( F_6 ( V_10 L_26 , V_4 -> V_7 ) ) ;
V_6 = V_4 -> V_7 ;
if ( F_28 ( V_2 ) || V_2 -> V_84 == 0 ) {
if ( F_28 ( V_2 ) ) {
if ( F_44 ( V_2 , V_4 ) )
goto V_83;
}
} else {
struct V_85 V_86 [ 1 ] ;
struct V_87 V_88 = {
. V_89 = F_45 ( V_90 ) ,
. V_91 = F_45 ( V_92 ) ,
. V_93 = F_46 (c->cleanmarker_size)
} ;
F_47 ( V_2 , V_4 , 1 ) ;
V_88 . V_94 = F_46 ( F_48 ( 0 , & V_88 , sizeof( struct V_87 ) - 4 ) ) ;
V_86 [ 0 ] . V_95 = ( unsigned char * ) & V_88 ;
V_86 [ 0 ] . V_96 = sizeof( V_88 ) ;
V_5 = F_49 ( V_2 , V_86 , 1 , V_4 -> V_7 , & V_71 ) ;
if ( V_5 || V_71 != sizeof( V_88 ) ) {
if ( V_5 )
F_6 ( V_14 L_27 ,
V_4 -> V_7 , V_5 ) ;
else
F_6 ( V_14 L_28 ,
V_4 -> V_7 , sizeof( V_88 ) , V_71 ) ;
goto V_83;
}
}
V_4 -> V_39 = V_2 -> V_11 ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
V_2 -> V_19 -= V_2 -> V_11 ;
V_2 -> V_39 += V_2 -> V_11 ;
if ( V_2 -> V_84 && ! F_28 ( V_2 ) )
F_50 ( V_2 , V_4 , V_4 -> V_7 | V_97 , V_2 -> V_84 , NULL ) ;
F_25 ( & V_4 -> V_17 , & V_2 -> V_98 ) ;
V_2 -> V_45 -- ;
V_2 -> V_99 ++ ;
F_51 ( V_2 , V_4 ) ;
F_52 ( V_2 , V_4 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_27 ( & V_2 -> V_42 ) ;
return;
V_83:
F_15 ( V_2 , V_4 , V_6 ) ;
return;
V_82:
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_26 ( V_2 ) ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_34 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
return;
}
