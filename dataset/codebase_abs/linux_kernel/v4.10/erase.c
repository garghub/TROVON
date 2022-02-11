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
F_5 ( 1 , L_1 ,
V_10 ,
V_4 -> V_7 , V_4 -> V_7 , V_4 -> V_7 + V_2 -> V_11 ) ;
V_9 = F_6 ( sizeof( struct V_8 ) + sizeof( struct V_12 ) , V_13 ) ;
if ( ! V_9 ) {
F_7 ( L_2 ) ;
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_10 ( & V_4 -> V_16 , & V_2 -> V_17 ) ;
V_2 -> V_18 -= V_2 -> V_11 ;
V_2 -> V_19 += V_2 -> V_11 ;
V_4 -> V_19 = V_2 -> V_11 ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
return;
}
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_20 = V_2 -> V_20 ;
V_9 -> V_21 = V_4 -> V_7 ;
V_9 -> V_22 = V_2 -> V_11 ;
V_9 -> V_23 = V_24 ;
V_9 -> V_25 = ( unsigned long ) ( & V_9 [ 1 ] ) ;
( (struct V_12 * ) V_9 -> V_25 ) -> V_4 = V_4 ;
( (struct V_12 * ) V_9 -> V_25 ) -> V_2 = V_2 ;
V_5 = F_13 ( V_2 -> V_20 , V_9 ) ;
if ( ! V_5 )
return;
V_6 = V_9 -> V_26 ;
F_14 ( V_9 ) ;
#endif
if ( V_5 == - V_27 || V_5 == - V_28 ) {
F_5 ( 1 , L_3 ,
V_4 -> V_7 , V_5 ) ;
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_10 ( & V_4 -> V_16 , & V_2 -> V_17 ) ;
V_2 -> V_18 -= V_2 -> V_11 ;
V_2 -> V_19 += V_2 -> V_11 ;
V_4 -> V_19 = V_2 -> V_11 ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
return;
}
if ( V_5 == - V_29 )
F_7 ( L_4 ,
V_4 -> V_7 ) ;
else
F_7 ( L_5 ,
V_4 -> V_7 , V_5 ) ;
F_15 ( V_2 , V_4 , V_6 ) ;
}
int F_16 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 ;
int V_31 = 0 ;
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
while ( ! F_17 ( & V_2 -> V_32 ) ||
! F_17 ( & V_2 -> V_17 ) ) {
if ( ! F_17 ( & V_2 -> V_32 ) ) {
V_4 = F_18 ( V_2 -> V_32 . V_33 , struct V_3 , V_16 ) ;
F_10 ( & V_4 -> V_16 , & V_2 -> V_34 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_19 ( V_2 , V_4 ) ;
V_31 ++ ;
if ( ! -- V_30 ) {
F_5 ( 1 , L_6 ) ;
goto V_35;
}
} else if ( ! F_17 ( & V_2 -> V_17 ) ) {
V_4 = F_18 ( V_2 -> V_17 . V_33 , struct V_3 , V_16 ) ;
F_5 ( 1 , L_7 ,
V_4 -> V_7 ) ;
F_20 ( & V_4 -> V_16 ) ;
V_2 -> V_18 += V_2 -> V_11 ;
V_2 -> V_36 -= V_4 -> V_36 ;
V_2 -> V_37 -= V_4 -> V_37 ;
V_2 -> V_38 -= V_4 -> V_38 ;
V_2 -> V_19 -= V_4 -> V_19 ;
V_4 -> V_36 = V_4 -> V_38 = V_4 -> V_19 = V_4 -> V_37 = 0 ;
F_21 ( V_2 , V_4 ) ;
F_22 ( & V_4 -> V_16 , & V_2 -> V_39 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_1 ( V_2 , V_4 ) ;
} else {
F_23 () ;
}
F_24 () ;
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
}
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
V_35:
F_5 ( 1 , L_8 ) ;
return V_31 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_5 ( 1 , L_9 , V_4 -> V_7 ) ;
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_25 ( & V_4 -> V_16 , & V_2 -> V_32 ) ;
F_26 ( V_2 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_27 ( & V_2 -> V_40 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_6 )
{
if ( F_28 ( V_2 ) && ( V_6 != ( T_1 ) V_41 ) ) {
if ( ! F_29 ( V_2 , V_4 , V_6 ) ) {
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_10 ( & V_4 -> V_16 , & V_2 -> V_17 ) ;
V_2 -> V_18 -= V_2 -> V_11 ;
V_2 -> V_19 += V_2 -> V_11 ;
V_4 -> V_19 = V_2 -> V_11 ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
return;
}
}
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
V_2 -> V_18 -= V_2 -> V_11 ;
V_2 -> V_42 += V_2 -> V_11 ;
F_10 ( & V_4 -> V_16 , & V_2 -> V_43 ) ;
V_2 -> V_44 -- ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_27 ( & V_2 -> V_40 ) ;
}
static void V_24 ( struct V_8 * V_9 )
{
struct V_12 * V_25 = ( void * ) V_9 -> V_25 ;
if( V_9 -> V_45 != V_46 ) {
F_7 ( L_10 ,
( unsigned long long ) V_9 -> V_21 , V_9 -> V_45 ) ;
F_15 ( V_25 -> V_2 , V_25 -> V_4 , V_9 -> V_26 ) ;
} else {
F_4 ( V_25 -> V_2 , V_25 -> V_4 ) ;
}
F_14 ( V_9 ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
struct V_47 * V_48 , struct V_3 * V_4 )
{
struct V_49 * V_50 = NULL ;
struct V_47 * * V_51 ;
V_51 = & V_48 -> V_52 ;
while ( 1 ) {
if ( ! ( * V_51 ) -> V_52 ) {
V_50 = (struct V_49 * ) ( * V_51 ) ;
V_51 = & V_50 -> V_53 ;
continue;
}
if ( F_31 ( ( * V_51 ) -> V_54 ) == V_4 -> V_7 ) {
struct V_47 * V_55 ;
V_55 = * V_51 ;
* V_51 = V_55 -> V_52 ;
V_55 -> V_52 = NULL ;
if ( V_55 == V_48 )
break;
continue;
}
V_51 = & ( ( * V_51 ) -> V_52 ) ;
}
if ( ! V_50 ) {
F_32 ( L_11
L_12 ) ;
return;
}
F_5 ( 1 , L_13 ,
V_4 -> V_7 , V_4 -> V_7 + V_2 -> V_11 , V_50 -> V_56 ) ;
F_33 ({
int i=0;
struct jffs2_raw_node_ref *this;
printk(KERN_DEBUG L_14);
this = ic->nodes;
printk(KERN_DEBUG);
while(this) {
pr_cont(L_15,
ref_offset(this), ref_flags(this));
if (++i == 5) {
printk(KERN_DEBUG);
i=0;
}
this = this->next_in_ino;
}
pr_cont(L_16);
}) ;
switch ( V_50 -> V_57 ) {
#ifdef F_34
case V_58 :
F_35 ( V_2 , (struct V_59 * ) V_50 ) ;
break;
case V_60 :
F_36 ( V_2 , (struct V_61 * ) V_50 ) ;
break;
#endif
default:
if ( V_50 -> V_53 == ( void * ) V_50 && V_50 -> V_62 == 0 )
F_37 ( V_2 , V_50 ) ;
}
}
void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_47 * V_63 , * V_48 ;
F_5 ( 1 , L_17 ,
V_4 -> V_7 ) ;
V_63 = V_48 = V_4 -> V_64 ;
while ( V_48 ) {
if ( V_48 -> V_54 == V_65 ) {
V_48 = V_48 -> V_52 ;
F_38 ( V_63 ) ;
V_63 = V_48 ;
continue;
}
if ( V_48 -> V_54 != V_66 && V_48 -> V_52 )
F_30 ( V_2 , V_48 , V_4 ) ;
V_48 ++ ;
}
V_4 -> V_64 = V_4 -> V_67 = NULL ;
}
static int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * V_6 )
{
void * V_68 ;
T_1 V_69 ;
T_2 V_70 ;
int V_5 ;
unsigned long * V_71 ;
V_5 = F_40 ( V_2 -> V_20 , V_4 -> V_7 , V_2 -> V_11 , & V_70 ,
& V_68 , NULL ) ;
if ( V_5 != - V_72 ) {
if ( V_5 ) {
F_5 ( 1 , L_18 , V_5 ) ;
goto V_73;
}
if ( V_70 < V_2 -> V_11 ) {
F_5 ( 1 , L_19 ,
V_70 ) ;
F_41 ( V_2 -> V_20 , V_4 -> V_7 , V_70 ) ;
goto V_73;
}
V_71 = V_68 - sizeof( * V_71 ) ;
V_70 /= sizeof( * V_71 ) ;
do {
if ( * ++ V_71 != ~ 0 )
break;
} while( -- V_70 );
F_41 ( V_2 -> V_20 , V_4 -> V_7 , V_2 -> V_11 ) ;
if ( V_70 ) {
F_7 ( L_20 ,
* V_71 ,
V_4 -> V_7 +
V_2 -> V_11 - V_70 * sizeof( * V_71 ) ) ;
return - V_74 ;
}
return 0 ;
}
V_73:
V_68 = F_6 ( V_75 , V_13 ) ;
if ( ! V_68 ) {
F_7 ( L_21 ,
V_4 -> V_7 ) ;
return - V_28 ;
}
F_5 ( 1 , L_22 , V_4 -> V_7 ) ;
for ( V_69 = V_4 -> V_7 ; V_69 < V_4 -> V_7 + V_2 -> V_11 ; ) {
T_1 V_76 = F_42 ( ( T_1 ) V_75 , V_4 -> V_7 + V_2 -> V_11 - V_69 ) ;
int V_77 ;
* V_6 = V_69 ;
V_5 = F_43 ( V_2 -> V_20 , V_69 , V_76 , & V_70 , V_68 ) ;
if ( V_5 ) {
F_7 ( L_23 ,
V_69 , V_5 ) ;
V_5 = - V_74 ;
goto V_78;
}
if ( V_70 != V_76 ) {
F_7 ( L_24 ,
V_69 , V_76 , V_70 ) ;
V_5 = - V_74 ;
goto V_78;
}
for ( V_77 = 0 ; V_77 < V_76 ; V_77 += sizeof( unsigned long ) ) {
unsigned long * V_79 = V_68 + V_77 ;
if ( * V_79 + 1 ) {
* V_6 += V_77 ;
F_7 ( L_25 ,
* V_79 , * V_6 ) ;
V_5 = - V_74 ;
goto V_78;
}
}
V_69 += V_76 ;
F_24 () ;
}
V_5 = 0 ;
V_78:
F_14 ( V_68 ) ;
return V_5 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_70 ;
int V_5 ;
T_1 V_80 ( V_6 ) ;
switch ( F_39 ( V_2 , V_4 , & V_6 ) ) {
case - V_28 : goto V_81;
case - V_74 : goto V_82;
}
F_5 ( 1 , L_26 , V_4 -> V_7 ) ;
V_6 = V_4 -> V_7 ;
if ( F_28 ( V_2 ) || V_2 -> V_83 == 0 ) {
if ( F_28 ( V_2 ) ) {
if ( F_44 ( V_2 , V_4 ) )
goto V_82;
}
} else {
struct V_84 V_85 [ 1 ] ;
struct V_86 V_87 = {
. V_88 = F_45 ( V_89 ) ,
. V_90 = F_45 ( V_91 ) ,
. V_92 = F_46 (c->cleanmarker_size)
} ;
F_47 ( V_2 , V_4 , 1 ) ;
V_87 . V_93 = F_46 ( F_48 ( 0 , & V_87 , sizeof( struct V_86 ) - 4 ) ) ;
V_85 [ 0 ] . V_94 = ( unsigned char * ) & V_87 ;
V_85 [ 0 ] . V_95 = sizeof( V_87 ) ;
V_5 = F_49 ( V_2 , V_85 , 1 , V_4 -> V_7 , & V_70 ) ;
if ( V_5 || V_70 != sizeof( V_87 ) ) {
if ( V_5 )
F_7 ( L_27 ,
V_4 -> V_7 , V_5 ) ;
else
F_7 ( L_28 ,
V_4 -> V_7 , sizeof( V_87 ) , V_70 ) ;
goto V_82;
}
}
V_4 -> V_37 = V_2 -> V_11 ;
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
V_2 -> V_18 -= V_2 -> V_11 ;
V_2 -> V_37 += V_2 -> V_11 ;
if ( V_2 -> V_83 && ! F_28 ( V_2 ) )
F_50 ( V_2 , V_4 , V_4 -> V_7 | V_96 , V_2 -> V_83 , NULL ) ;
F_25 ( & V_4 -> V_16 , & V_2 -> V_97 ) ;
V_2 -> V_44 -- ;
V_2 -> V_98 ++ ;
F_51 ( V_2 , V_4 ) ;
F_52 ( V_2 , V_4 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_27 ( & V_2 -> V_40 ) ;
return;
V_82:
F_15 ( V_2 , V_4 , V_6 ) ;
return;
V_81:
F_8 ( & V_2 -> V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_26 ( V_2 ) ;
F_10 ( & V_4 -> V_16 , & V_2 -> V_32 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_12 ( & V_2 -> V_14 ) ;
return;
}
