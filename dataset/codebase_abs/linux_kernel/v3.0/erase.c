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
V_5 = V_2 -> V_21 -> V_29 ( V_2 -> V_21 , V_9 ) ;
if ( ! V_5 )
return;
V_6 = V_9 -> V_27 ;
F_13 ( V_9 ) ;
#endif
if ( V_5 == - V_30 || V_5 == - V_31 ) {
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
if ( V_5 == - V_32 )
F_6 ( V_14 L_4 , V_4 -> V_7 ) ;
else
F_6 ( V_14 L_5 , V_4 -> V_7 , V_5 ) ;
F_14 ( V_2 , V_4 , V_6 ) ;
}
int F_15 ( struct V_1 * V_2 , int V_33 )
{
struct V_3 * V_4 ;
int V_34 = 0 ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
while ( ! F_16 ( & V_2 -> V_35 ) ||
! F_16 ( & V_2 -> V_18 ) ) {
if ( ! F_16 ( & V_2 -> V_35 ) ) {
V_4 = F_17 ( V_2 -> V_35 . V_36 , struct V_3 , V_17 ) ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_37 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_18 ( V_2 , V_4 ) ;
V_34 ++ ;
if ( ! -- V_33 ) {
F_5 ( F_6 ( V_10 L_6 ) ) ;
goto V_38;
}
} else if ( ! F_16 ( & V_2 -> V_18 ) ) {
V_4 = F_17 ( V_2 -> V_18 . V_36 , struct V_3 , V_17 ) ;
F_5 ( F_6 ( V_10 L_7 , V_4 -> V_7 ) ) ;
F_19 ( & V_4 -> V_17 ) ;
V_2 -> V_19 += V_2 -> V_11 ;
V_2 -> V_39 -= V_4 -> V_39 ;
V_2 -> V_40 -= V_4 -> V_40 ;
V_2 -> V_41 -= V_4 -> V_41 ;
V_2 -> V_20 -= V_4 -> V_20 ;
V_4 -> V_39 = V_4 -> V_41 = V_4 -> V_20 = V_4 -> V_40 = 0 ;
F_20 ( V_2 , V_4 ) ;
F_21 ( & V_4 -> V_17 , & V_2 -> V_42 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_1 ( V_2 , V_4 ) ;
} else {
F_22 () ;
}
F_23 () ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
}
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
V_38:
F_5 ( F_6 ( V_10 L_8 ) ) ;
return V_34 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_5 ( F_6 ( V_10 L_9 , V_4 -> V_7 ) ) ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_24 ( & V_4 -> V_17 , & V_2 -> V_35 ) ;
F_25 ( V_2 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_26 ( & V_2 -> V_43 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_6 )
{
if ( F_27 ( V_2 ) && ( V_6 != ( T_1 ) V_28 ) ) {
if ( ! F_28 ( V_2 , V_4 , V_6 ) ) {
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
V_2 -> V_44 += V_2 -> V_11 ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_45 ) ;
V_2 -> V_46 -- ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_26 ( & V_2 -> V_43 ) ;
}
static void V_25 ( struct V_8 * V_9 )
{
struct V_12 * V_26 = ( void * ) V_9 -> V_26 ;
if( V_9 -> V_47 != V_48 ) {
F_6 ( V_14 L_10 ,
( unsigned long long ) V_9 -> V_22 , V_9 -> V_47 ) ;
F_14 ( V_26 -> V_2 , V_26 -> V_4 , V_9 -> V_27 ) ;
} else {
F_4 ( V_26 -> V_2 , V_26 -> V_4 ) ;
}
F_13 ( V_9 ) ;
}
static inline void F_29 ( struct V_1 * V_2 ,
struct V_49 * V_50 , struct V_3 * V_4 )
{
struct V_51 * V_52 = NULL ;
struct V_49 * * V_53 ;
V_53 = & V_50 -> V_54 ;
while ( 1 ) {
if ( ! ( * V_53 ) -> V_54 ) {
V_52 = (struct V_51 * ) ( * V_53 ) ;
V_53 = & V_52 -> V_55 ;
continue;
}
if ( F_30 ( ( * V_53 ) -> V_56 ) == V_4 -> V_7 ) {
struct V_49 * V_57 ;
V_57 = * V_53 ;
* V_53 = V_57 -> V_54 ;
V_57 -> V_54 = NULL ;
if ( V_57 == V_50 )
break;
continue;
}
V_53 = & ( ( * V_53 ) -> V_54 ) ;
}
if ( ! V_52 ) {
F_31 ( L_11
L_12 ) ;
return;
}
F_5 ( F_6 ( V_10 L_13 ,
V_4 -> V_7 , V_4 -> V_7 + V_2 -> V_11 , V_52 -> V_58 ) ) ;
F_32 ({
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
switch ( V_52 -> V_59 ) {
#ifdef F_33
case V_60 :
F_34 ( V_2 , (struct V_61 * ) V_52 ) ;
break;
case V_62 :
F_35 ( V_2 , (struct V_63 * ) V_52 ) ;
break;
#endif
default:
if ( V_52 -> V_55 == ( void * ) V_52 && V_52 -> V_64 == 0 )
F_36 ( V_2 , V_52 ) ;
}
}
void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_49 * V_65 , * V_50 ;
F_5 ( F_6 ( V_10 L_17 , V_4 -> V_7 ) ) ;
V_65 = V_50 = V_4 -> V_66 ;
while ( V_50 ) {
if ( V_50 -> V_56 == V_67 ) {
V_50 = V_50 -> V_54 ;
F_37 ( V_65 ) ;
V_65 = V_50 ;
continue;
}
if ( V_50 -> V_56 != V_68 && V_50 -> V_54 )
F_29 ( V_2 , V_50 , V_4 ) ;
V_50 ++ ;
}
V_4 -> V_66 = V_4 -> V_69 = NULL ;
}
static int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * V_6 )
{
void * V_70 ;
T_1 V_71 ;
T_2 V_72 ;
int V_5 = - V_73 ;
if ( V_2 -> V_21 -> V_74 ) {
unsigned long * V_75 ;
V_5 = V_2 -> V_21 -> V_74 ( V_2 -> V_21 , V_4 -> V_7 , V_2 -> V_11 ,
& V_72 , & V_70 , NULL ) ;
if ( V_5 ) {
F_5 ( F_6 ( V_10 L_18 , V_5 ) ) ;
goto V_76;
}
if ( V_72 < V_2 -> V_11 ) {
F_5 ( F_6 ( V_10 L_19 , V_72 ) ) ;
V_2 -> V_21 -> V_77 ( V_2 -> V_21 , V_4 -> V_7 , V_72 ) ;
goto V_76;
}
V_75 = V_70 - sizeof( * V_75 ) ;
V_72 /= sizeof( * V_75 ) ;
do {
if ( * ++ V_75 != ~ 0 )
break;
} while( -- V_72 );
V_2 -> V_21 -> V_77 ( V_2 -> V_21 , V_4 -> V_7 , V_2 -> V_11 ) ;
if ( V_72 ) {
F_6 ( V_14 L_20 ,
* V_75 , V_4 -> V_7 + V_2 -> V_11 - V_72 * sizeof( * V_75 ) ) ;
return - V_73 ;
}
return 0 ;
}
V_76:
V_70 = F_7 ( V_78 , V_13 ) ;
if ( ! V_70 ) {
F_6 ( V_14 L_21 , V_4 -> V_7 ) ;
return - V_31 ;
}
F_5 ( F_6 ( V_10 L_22 , V_4 -> V_7 ) ) ;
for ( V_71 = V_4 -> V_7 ; V_71 < V_4 -> V_7 + V_2 -> V_11 ; ) {
T_1 V_79 = F_39 ( ( T_1 ) V_78 , V_4 -> V_7 + V_2 -> V_11 - V_71 ) ;
int V_80 ;
* V_6 = V_71 ;
V_5 = V_2 -> V_21 -> V_81 ( V_2 -> V_21 , V_71 , V_79 , & V_72 , V_70 ) ;
if ( V_5 ) {
F_6 ( V_14 L_23 , V_71 , V_5 ) ;
V_5 = - V_73 ;
goto V_82;
}
if ( V_72 != V_79 ) {
F_6 ( V_14 L_24 , V_71 , V_79 , V_72 ) ;
V_5 = - V_73 ;
goto V_82;
}
for ( V_80 = 0 ; V_80 < V_79 ; V_80 += sizeof( unsigned long ) ) {
unsigned long * V_83 = V_70 + V_80 ;
if ( * V_83 + 1 ) {
* V_6 += V_80 ;
F_6 ( V_14 L_25 , * V_83 , * V_6 ) ;
V_5 = - V_73 ;
goto V_82;
}
}
V_71 += V_79 ;
F_23 () ;
}
V_5 = 0 ;
V_82:
F_13 ( V_70 ) ;
return V_5 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_72 ;
int V_5 ;
T_1 V_84 ( V_6 ) ;
switch ( F_38 ( V_2 , V_4 , & V_6 ) ) {
case - V_31 : goto V_85;
case - V_73 : goto V_86;
}
F_5 ( F_6 ( V_10 L_26 , V_4 -> V_7 ) ) ;
V_6 = V_4 -> V_7 ;
if ( F_27 ( V_2 ) || V_2 -> V_87 == 0 ) {
if ( F_27 ( V_2 ) ) {
if ( F_40 ( V_2 , V_4 ) )
goto V_86;
}
} else {
struct V_88 V_89 [ 1 ] ;
struct V_90 V_91 = {
. V_92 = F_41 ( V_93 ) ,
. V_94 = F_41 ( V_95 ) ,
. V_96 = F_42 (c->cleanmarker_size)
} ;
F_43 ( V_2 , V_4 , 1 ) ;
V_91 . V_97 = F_42 ( F_44 ( 0 , & V_91 , sizeof( struct V_90 ) - 4 ) ) ;
V_89 [ 0 ] . V_98 = ( unsigned char * ) & V_91 ;
V_89 [ 0 ] . V_99 = sizeof( V_91 ) ;
V_5 = F_45 ( V_2 , V_89 , 1 , V_4 -> V_7 , & V_72 ) ;
if ( V_5 || V_72 != sizeof( V_91 ) ) {
if ( V_5 )
F_6 ( V_14 L_27 ,
V_4 -> V_7 , V_5 ) ;
else
F_6 ( V_14 L_28 ,
V_4 -> V_7 , sizeof( V_91 ) , V_72 ) ;
goto V_86;
}
}
V_4 -> V_40 = V_2 -> V_11 ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
V_2 -> V_19 -= V_2 -> V_11 ;
V_2 -> V_40 += V_2 -> V_11 ;
if ( V_2 -> V_87 && ! F_27 ( V_2 ) )
F_46 ( V_2 , V_4 , V_4 -> V_7 | V_100 , V_2 -> V_87 , NULL ) ;
F_24 ( & V_4 -> V_17 , & V_2 -> V_101 ) ;
V_2 -> V_46 -- ;
V_2 -> V_102 ++ ;
F_47 ( V_2 , V_4 ) ;
F_48 ( V_2 , V_4 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_26 ( & V_2 -> V_43 ) ;
return;
V_86:
F_14 ( V_2 , V_4 , V_6 ) ;
return;
V_85:
F_8 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_25 ( V_2 ) ;
F_10 ( & V_4 -> V_17 , & V_2 -> V_35 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( & V_2 -> V_15 ) ;
return;
}
