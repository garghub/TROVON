static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_2 ( V_2 , V_3 ) ;
if ( F_3 ( V_3 ) )
F_4 ( V_2 ) ;
}
static int F_5 ( struct V_3 * V_3 , long V_4 , int V_5 [ V_6 ] )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_8 ) ;
int V_12 = V_11 -> V_13 ;
unsigned long V_14 = V_11 -> V_15 ,
V_16 = V_11 -> V_17 ;
int V_18 = 0 ;
if ( V_4 < 0 ) {
F_7 ( L_1 ) ;
} else if ( V_4 < V_19 ) {
V_5 [ V_18 ++ ] = V_4 ;
} else if ( ( V_4 -= V_19 ) < V_14 ) {
V_5 [ V_18 ++ ] = V_19 ;
V_5 [ V_18 ++ ] = V_4 ;
} else if ( ( V_4 -= V_14 ) < V_16 ) {
V_5 [ V_18 ++ ] = V_19 + 1 ;
V_5 [ V_18 ++ ] = V_4 >> V_12 ;
V_5 [ V_18 ++ ] = V_4 & ( V_14 - 1 ) ;
} else if ( ( ( V_4 -= V_16 ) >> ( V_12 * 2 ) ) < V_14 ) {
V_5 [ V_18 ++ ] = V_19 + 2 ;
V_5 [ V_18 ++ ] = V_4 >> ( V_12 * 2 ) ;
V_5 [ V_18 ++ ] = ( V_4 >> V_12 ) & ( V_14 - 1 ) ;
V_5 [ V_18 ++ ] = V_4 & ( V_14 - 1 ) ;
} else {
;
}
return V_18 ;
}
static inline int F_8 ( struct V_10 * V_11 , T_1 V_20 )
{
return V_11 -> V_21 + F_9 ( V_11 , V_20 ) ;
}
static inline void F_10 ( T_2 * V_22 , struct V_1 * V_2 , T_1 * V_23 )
{
V_22 -> V_24 = * ( V_22 -> V_22 = V_23 ) ;
V_22 -> V_2 = V_2 ;
}
static inline int F_11 ( T_2 * V_25 , T_2 * V_26 )
{
while ( V_25 <= V_26 && V_25 -> V_24 == * V_25 -> V_22 )
V_25 ++ ;
return ( V_25 > V_26 ) ;
}
static inline T_1 * F_12 ( struct V_1 * V_2 )
{
return ( T_1 * ) ( ( char * ) V_2 -> V_27 + V_2 -> V_28 ) ;
}
static T_2 * F_13 ( struct V_3 * V_3 ,
int V_29 ,
int V_5 [] ,
T_2 V_30 [] ,
int * V_31 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
T_2 * V_22 = V_30 ;
struct V_1 * V_2 ;
* V_31 = 0 ;
F_10 ( V_30 , NULL , F_14 ( V_3 ) -> V_32 + * V_5 ) ;
if ( ! V_22 -> V_24 )
goto V_33;
while ( -- V_29 ) {
int V_4 = F_8 ( F_6 ( V_8 ) , V_22 -> V_24 ) ;
V_2 = F_15 ( V_8 , V_4 ) ;
if ( ! V_2 )
goto V_34;
if ( ! F_11 ( V_30 , V_22 ) )
goto V_35;
F_10 ( ++ V_22 , V_2 , ( T_1 * ) V_2 -> V_27 + * ++ V_5 ) ;
if ( ! V_22 -> V_24 )
goto V_33;
}
return NULL ;
V_35:
F_16 ( V_2 ) ;
* V_31 = - V_36 ;
goto V_33;
V_34:
* V_31 = - V_37 ;
V_33:
return V_22 ;
}
static int F_17 ( struct V_3 * V_3 ,
int V_38 ,
int * V_5 ,
T_2 * V_39 )
{
int V_40 = V_3 -> V_9 -> V_41 ;
int V_18 = 0 ;
int V_42 ;
V_39 [ 0 ] . V_24 = F_18 ( V_3 -> V_9 ) ;
if ( V_39 [ 0 ] . V_24 ) for ( V_18 = 1 ; V_18 < V_38 ; V_18 ++ ) {
struct V_1 * V_2 ;
int V_43 ;
V_39 [ V_18 ] . V_24 = F_18 ( V_3 -> V_9 ) ;
if ( ! V_39 [ V_18 ] . V_24 )
break;
V_43 = F_8 ( F_6 ( V_3 -> V_9 ) , V_39 [ V_18 - 1 ] . V_24 ) ;
V_2 = F_19 ( V_3 -> V_9 , V_43 ) ;
F_20 ( V_2 ) ;
memset ( V_2 -> V_27 , 0 , V_40 ) ;
V_39 [ V_18 ] . V_2 = V_2 ;
V_39 [ V_18 ] . V_22 = ( T_1 * ) V_2 -> V_27 + V_5 [ V_18 ] ;
* V_39 [ V_18 ] . V_22 = V_39 [ V_18 ] . V_24 ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_1 ( V_2 , V_3 ) ;
}
if ( V_18 == V_38 )
return 0 ;
for ( V_42 = 1 ; V_42 < V_18 ; V_42 ++ )
F_23 ( V_39 [ V_42 ] . V_2 ) ;
for ( V_42 = 0 ; V_42 < V_18 ; V_42 ++ )
F_24 ( V_3 -> V_9 , V_39 [ V_42 ] . V_24 ) ;
return - V_44 ;
}
static inline int F_25 ( struct V_3 * V_3 ,
T_2 V_30 [] ,
T_2 * V_45 ,
int V_38 )
{
int V_42 ;
F_26 ( & V_46 ) ;
if ( ! F_11 ( V_30 , V_45 - 1 ) || * V_45 -> V_22 )
goto V_35;
* V_45 -> V_22 = V_45 -> V_24 ;
F_27 ( & V_46 ) ;
V_3 -> V_47 = F_28 ( V_3 ) ;
if ( V_45 -> V_2 )
F_1 ( V_45 -> V_2 , V_3 ) ;
if ( F_3 ( V_3 ) )
F_29 ( V_3 ) ;
else
F_30 ( V_3 ) ;
return 0 ;
V_35:
F_27 ( & V_46 ) ;
for ( V_42 = 1 ; V_42 < V_38 ; V_42 ++ )
F_23 ( V_45 [ V_42 ] . V_2 ) ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ )
F_24 ( V_3 -> V_9 , V_45 [ V_42 ] . V_24 ) ;
return - V_36 ;
}
static int F_31 ( struct V_3 * V_3 , T_3 V_48 , struct V_1 * V_49 , int V_50 )
{
int V_31 = - V_37 ;
int V_5 [ V_6 ] ;
T_2 V_30 [ V_6 ] ;
struct V_7 * V_8 = V_3 -> V_9 ;
T_2 * V_51 ;
int V_52 ;
int V_29 = F_5 ( V_3 , V_48 , V_5 ) ;
if ( V_29 == 0 )
goto V_53;
V_54:
F_32 ( & V_46 ) ;
V_51 = F_13 ( V_3 , V_29 , V_5 , V_30 , & V_31 ) ;
F_33 ( & V_46 ) ;
if ( ! V_51 ) {
V_55:
F_34 ( V_49 , V_8 , F_8 ( F_6 ( V_8 ) ,
V_30 [ V_29 - 1 ] . V_24 ) ) ;
V_51 = V_30 + V_29 - 1 ;
goto V_56;
}
if ( ! V_50 || V_31 == - V_37 ) {
V_56:
while ( V_51 > V_30 ) {
F_16 ( V_51 -> V_2 ) ;
V_51 -- ;
}
V_53:
return V_31 ;
}
if ( V_31 == - V_36 )
goto V_35;
V_52 = ( V_30 + V_29 ) - V_51 ;
V_31 = F_17 ( V_3 , V_52 , V_5 + ( V_51 - V_30 ) , V_51 ) ;
if ( V_31 )
goto V_56;
if ( F_25 ( V_3 , V_30 , V_51 , V_52 ) < 0 )
goto V_35;
F_35 ( V_49 ) ;
goto V_55;
V_35:
while ( V_51 > V_30 ) {
F_16 ( V_51 -> V_2 ) ;
V_51 -- ;
}
goto V_54;
}
static inline int F_36 ( T_1 * V_22 , T_1 * V_57 )
{
while ( V_22 < V_57 )
if ( * V_22 ++ )
return 0 ;
return 1 ;
}
static T_2 * F_37 ( struct V_3 * V_3 ,
int V_29 ,
int V_5 [] ,
T_2 V_30 [] ,
T_1 * V_58 )
{
T_2 * V_51 , * V_22 ;
int V_59 , V_31 ;
* V_58 = 0 ;
for ( V_59 = V_29 ; V_59 > 1 && ! V_5 [ V_59 - 1 ] ; V_59 -- )
;
F_26 ( & V_46 ) ;
V_51 = F_13 ( V_3 , V_59 , V_5 , V_30 , & V_31 ) ;
if ( ! V_51 )
V_51 = V_30 + V_59 - 1 ;
if ( ! V_51 -> V_24 && * V_51 -> V_22 ) {
F_27 ( & V_46 ) ;
goto V_60;
}
for ( V_22 = V_51 ; V_22 > V_30 && F_36 ( ( T_1 * ) V_22 -> V_2 -> V_27 , V_22 -> V_22 ) ; V_22 -- )
;
if ( V_22 == V_30 + V_59 - 1 && V_22 > V_30 ) {
V_22 -> V_22 -- ;
} else {
* V_58 = * V_22 -> V_22 ;
* V_22 -> V_22 = 0 ;
}
F_27 ( & V_46 ) ;
while ( V_51 > V_22 ) {
F_16 ( V_51 -> V_2 ) ;
V_51 -- ;
}
V_60:
return V_51 ;
}
static inline void F_38 ( struct V_3 * V_3 , T_1 * V_22 , T_1 * V_57 )
{
for ( ; V_22 < V_57 ; V_22 ++ ) {
T_1 V_20 = * V_22 ;
if ( V_20 ) {
* V_22 = 0 ;
F_24 ( V_3 -> V_9 , V_20 ) ;
F_30 ( V_3 ) ;
}
}
}
static void F_39 ( struct V_3 * V_3 , T_1 * V_22 , T_1 * V_57 , int V_29 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_3 -> V_9 ;
if ( V_29 -- ) {
for ( ; V_22 < V_57 ; V_22 ++ ) {
int V_4 ;
T_1 V_20 = * V_22 ;
if ( ! V_20 )
continue;
* V_22 = 0 ;
V_4 = F_8 ( F_6 ( V_8 ) , V_20 ) ;
V_2 = F_15 ( V_8 , V_4 ) ;
if ( ! V_2 )
continue;
F_39 ( V_3 , ( T_1 * ) V_2 -> V_27 ,
F_12 ( V_2 ) , V_29 ) ;
F_23 ( V_2 ) ;
F_24 ( V_8 , V_20 ) ;
F_30 ( V_3 ) ;
}
} else
F_38 ( V_3 , V_22 , V_57 ) ;
}
void F_40 ( struct V_3 * V_3 )
{
T_1 * V_32 = F_14 ( V_3 ) -> V_32 ;
int V_5 [ V_6 ] ;
T_2 V_30 [ V_6 ] ;
T_2 * V_51 ;
T_1 V_20 = 0 ;
int V_18 ;
long V_48 ;
unsigned V_40 ;
if ( ! ( F_41 ( V_3 -> V_61 ) || F_42 ( V_3 -> V_61 ) ||
F_43 ( V_3 -> V_61 ) ) )
return;
V_40 = V_3 -> V_9 -> V_41 ;
V_48 = ( V_3 -> V_62 + V_40 - 1 )
>> V_3 -> V_9 -> V_63 ;
F_44 ( V_3 -> V_64 , V_3 -> V_62 , F_31 ) ;
V_18 = F_5 ( V_3 , V_48 , V_5 ) ;
if ( V_18 == 0 )
return;
if ( V_18 == 1 ) {
F_38 ( V_3 , V_32 + V_5 [ 0 ] , V_32 + V_19 ) ;
goto V_65;
}
V_51 = F_37 ( V_3 , V_18 , V_5 , V_30 , & V_20 ) ;
if ( V_20 ) {
if ( V_51 == V_30 )
F_30 ( V_3 ) ;
else
F_1 ( V_51 -> V_2 , V_3 ) ;
F_39 ( V_3 , & V_20 , & V_20 + 1 , ( V_30 + V_18 - 1 ) - V_51 ) ;
}
while ( V_51 > V_30 ) {
F_39 ( V_3 , V_51 -> V_22 + 1 , F_12 ( V_51 -> V_2 ) ,
( V_30 + V_18 - 1 ) - V_51 ) ;
F_1 ( V_51 -> V_2 , V_3 ) ;
F_16 ( V_51 -> V_2 ) ;
V_51 -- ;
}
V_65:
while ( V_18 < V_6 ) {
V_20 = V_32 [ V_19 + V_18 - 1 ] ;
if ( V_20 ) {
V_32 [ V_19 + V_18 - 1 ] = 0 ;
F_30 ( V_3 ) ;
F_39 ( V_3 , & V_20 , & V_20 + 1 , V_18 ) ;
}
V_18 ++ ;
}
V_3 -> V_66 = V_3 -> V_47 = F_28 ( V_3 ) ;
if ( F_3 ( V_3 ) )
F_29 ( V_3 ) ;
else
F_30 ( V_3 ) ;
}
static unsigned F_45 ( struct V_7 * V_67 , T_4 V_68 )
{
struct V_10 * V_11 = F_6 ( V_67 ) ;
int V_12 = V_11 -> V_13 ;
unsigned V_69 , V_70 , V_71 = V_19 , V_42 = V_6 ;
V_69 = ( V_68 + V_67 -> V_41 - 1 ) >> V_67 -> V_63 ;
V_70 = V_69 ;
while ( -- V_42 && V_69 > V_71 ) {
V_69 = ( ( V_69 - V_71 - 1 ) >> V_12 ) + 1 ;
V_70 += V_69 ;
V_71 = 1 ;
}
return V_69 ;
}
int F_46 ( const struct V_72 * V_72 , struct V_73 * V_74 ,
T_5 V_75 , unsigned int V_76 )
{
struct V_7 * V_67 = V_72 -> V_77 -> V_78 ;
F_47 ( F_48 ( V_72 -> V_77 ) , V_74 ) ;
V_74 -> V_69 = ( V_67 -> V_41 / 512 ) * F_45 ( V_67 , V_74 -> V_68 ) ;
V_74 -> V_79 = V_67 -> V_41 ;
return 0 ;
}
static int F_49 ( struct V_80 * V_80 , struct V_81 * V_82 )
{
return F_50 ( V_80 , F_31 , V_82 ) ;
}
static int F_51 ( struct V_83 * V_83 , struct V_80 * V_80 )
{
return F_52 ( V_80 , F_31 ) ;
}
int F_53 ( struct V_80 * V_80 , T_4 V_84 , unsigned V_85 )
{
return F_54 ( V_80 , V_84 , V_85 , F_31 ) ;
}
static void F_55 ( struct V_86 * V_87 , T_4 V_26 )
{
struct V_3 * V_3 = V_87 -> V_88 ;
if ( V_26 > V_3 -> V_62 ) {
F_56 ( V_3 , V_3 -> V_62 ) ;
F_40 ( V_3 ) ;
}
}
static int F_57 ( struct V_83 * V_83 , struct V_86 * V_87 ,
T_4 V_84 , unsigned V_85 , unsigned V_76 ,
struct V_80 * * V_89 , void * * V_90 )
{
int V_91 ;
V_91 = F_58 ( V_87 , V_84 , V_85 , V_76 , V_89 , F_31 ) ;
if ( F_59 ( V_91 ) )
F_55 ( V_87 , V_84 + V_85 ) ;
return V_91 ;
}
static T_3 F_60 ( struct V_86 * V_87 , T_3 V_4 )
{
return F_61 ( V_87 , V_4 , F_31 ) ;
}
