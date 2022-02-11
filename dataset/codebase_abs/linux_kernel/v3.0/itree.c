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
V_3 -> V_47 = V_48 ;
if ( V_45 -> V_2 )
F_1 ( V_45 -> V_2 , V_3 ) ;
if ( F_3 ( V_3 ) )
F_28 ( V_3 ) ;
else
F_29 ( V_3 ) ;
return 0 ;
V_35:
F_27 ( & V_46 ) ;
for ( V_42 = 1 ; V_42 < V_38 ; V_42 ++ )
F_23 ( V_45 [ V_42 ] . V_2 ) ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ )
F_24 ( V_3 -> V_9 , V_45 [ V_42 ] . V_24 ) ;
return - V_36 ;
}
static int F_30 ( struct V_3 * V_3 , T_3 V_49 , struct V_1 * V_50 , int V_51 )
{
int V_31 = - V_37 ;
int V_5 [ V_6 ] ;
T_2 V_30 [ V_6 ] ;
struct V_7 * V_8 = V_3 -> V_9 ;
T_2 * V_52 ;
int V_53 ;
int V_29 = F_5 ( V_3 , V_49 , V_5 ) ;
if ( V_29 == 0 )
goto V_54;
V_55:
F_31 ( & V_46 ) ;
V_52 = F_13 ( V_3 , V_29 , V_5 , V_30 , & V_31 ) ;
F_32 ( & V_46 ) ;
if ( ! V_52 ) {
V_56:
F_33 ( V_50 , V_8 , F_8 ( F_6 ( V_8 ) ,
V_30 [ V_29 - 1 ] . V_24 ) ) ;
V_52 = V_30 + V_29 - 1 ;
goto V_57;
}
if ( ! V_51 || V_31 == - V_37 ) {
V_57:
while ( V_52 > V_30 ) {
F_16 ( V_52 -> V_2 ) ;
V_52 -- ;
}
V_54:
return V_31 ;
}
if ( V_31 == - V_36 )
goto V_35;
V_53 = ( V_30 + V_29 ) - V_52 ;
V_31 = F_17 ( V_3 , V_53 , V_5 + ( V_52 - V_30 ) , V_52 ) ;
if ( V_31 )
goto V_57;
if ( F_25 ( V_3 , V_30 , V_52 , V_53 ) < 0 )
goto V_35;
F_34 ( V_50 ) ;
goto V_56;
V_35:
while ( V_52 > V_30 ) {
F_16 ( V_52 -> V_2 ) ;
V_52 -- ;
}
goto V_55;
}
static inline int F_35 ( T_1 * V_22 , T_1 * V_58 )
{
while ( V_22 < V_58 )
if ( * V_22 ++ )
return 0 ;
return 1 ;
}
static T_2 * F_36 ( struct V_3 * V_3 ,
int V_29 ,
int V_5 [] ,
T_2 V_30 [] ,
T_1 * V_59 )
{
T_2 * V_52 , * V_22 ;
int V_60 , V_31 ;
* V_59 = 0 ;
for ( V_60 = V_29 ; V_60 > 1 && ! V_5 [ V_60 - 1 ] ; V_60 -- )
;
F_26 ( & V_46 ) ;
V_52 = F_13 ( V_3 , V_60 , V_5 , V_30 , & V_31 ) ;
if ( ! V_52 )
V_52 = V_30 + V_60 - 1 ;
if ( ! V_52 -> V_24 && * V_52 -> V_22 ) {
F_27 ( & V_46 ) ;
goto V_61;
}
for ( V_22 = V_52 ; V_22 > V_30 && F_35 ( ( T_1 * ) V_22 -> V_2 -> V_27 , V_22 -> V_22 ) ; V_22 -- )
;
if ( V_22 == V_30 + V_60 - 1 && V_22 > V_30 ) {
V_22 -> V_22 -- ;
} else {
* V_59 = * V_22 -> V_22 ;
* V_22 -> V_22 = 0 ;
}
F_27 ( & V_46 ) ;
while ( V_52 > V_22 ) {
F_16 ( V_52 -> V_2 ) ;
V_52 -- ;
}
V_61:
return V_52 ;
}
static inline void F_37 ( struct V_3 * V_3 , T_1 * V_22 , T_1 * V_58 )
{
for ( ; V_22 < V_58 ; V_22 ++ ) {
T_1 V_20 = * V_22 ;
if ( V_20 ) {
* V_22 = 0 ;
F_24 ( V_3 -> V_9 , V_20 ) ;
F_29 ( V_3 ) ;
}
}
}
static void F_38 ( struct V_3 * V_3 , T_1 * V_22 , T_1 * V_58 , int V_29 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_3 -> V_9 ;
if ( V_29 -- ) {
for ( ; V_22 < V_58 ; V_22 ++ ) {
int V_4 ;
T_1 V_20 = * V_22 ;
if ( ! V_20 )
continue;
* V_22 = 0 ;
V_4 = F_8 ( F_6 ( V_8 ) , V_20 ) ;
V_2 = F_15 ( V_8 , V_4 ) ;
if ( ! V_2 )
continue;
F_38 ( V_3 , ( T_1 * ) V_2 -> V_27 ,
F_12 ( V_2 ) , V_29 ) ;
F_23 ( V_2 ) ;
F_24 ( V_8 , V_20 ) ;
F_29 ( V_3 ) ;
}
} else
F_37 ( V_3 , V_22 , V_58 ) ;
}
void F_39 ( struct V_3 * V_3 )
{
T_1 * V_32 = F_14 ( V_3 ) -> V_32 ;
int V_5 [ V_6 ] ;
T_2 V_30 [ V_6 ] ;
T_2 * V_52 ;
T_1 V_20 = 0 ;
int V_18 ;
long V_49 ;
unsigned V_40 ;
if ( ! ( F_40 ( V_3 -> V_62 ) || F_41 ( V_3 -> V_62 ) ||
F_42 ( V_3 -> V_62 ) ) )
return;
V_40 = V_3 -> V_9 -> V_41 ;
V_49 = ( V_3 -> V_63 + V_40 - 1 )
>> V_3 -> V_9 -> V_64 ;
F_43 ( V_3 -> V_65 , V_3 -> V_63 , F_30 ) ;
V_18 = F_5 ( V_3 , V_49 , V_5 ) ;
if ( V_18 == 0 )
return;
if ( V_18 == 1 ) {
F_37 ( V_3 , V_32 + V_5 [ 0 ] , V_32 + V_19 ) ;
goto V_66;
}
V_52 = F_36 ( V_3 , V_18 , V_5 , V_30 , & V_20 ) ;
if ( V_20 ) {
if ( V_52 == V_30 )
F_29 ( V_3 ) ;
else
F_1 ( V_52 -> V_2 , V_3 ) ;
F_38 ( V_3 , & V_20 , & V_20 + 1 , ( V_30 + V_18 - 1 ) - V_52 ) ;
}
while ( V_52 > V_30 ) {
F_38 ( V_3 , V_52 -> V_22 + 1 , F_12 ( V_52 -> V_2 ) ,
( V_30 + V_18 - 1 ) - V_52 ) ;
F_1 ( V_52 -> V_2 , V_3 ) ;
F_16 ( V_52 -> V_2 ) ;
V_52 -- ;
}
V_66:
while ( V_18 < V_6 ) {
V_20 = V_32 [ V_19 + V_18 - 1 ] ;
if ( V_20 ) {
V_32 [ V_19 + V_18 - 1 ] = 0 ;
F_29 ( V_3 ) ;
F_38 ( V_3 , & V_20 , & V_20 + 1 , V_18 ) ;
}
V_18 ++ ;
}
V_3 -> V_67 = V_3 -> V_47 = V_48 ;
if ( F_3 ( V_3 ) )
F_28 ( V_3 ) ;
else
F_29 ( V_3 ) ;
}
static unsigned F_44 ( struct V_7 * V_68 , T_4 V_69 )
{
struct V_10 * V_11 = F_6 ( V_68 ) ;
int V_12 = V_11 -> V_13 ;
unsigned V_70 , V_71 , V_72 = V_19 , V_42 = V_6 ;
V_70 = ( V_69 + V_68 -> V_41 - 1 ) >> V_68 -> V_64 ;
V_71 = V_70 ;
while ( -- V_42 && V_70 > V_72 ) {
V_70 = ( ( V_70 - V_72 - 1 ) >> V_12 ) + 1 ;
V_71 += V_70 ;
V_72 = 1 ;
}
return V_70 ;
}
int F_45 ( struct V_73 * V_74 , struct V_75 * V_75 , struct V_76 * V_77 )
{
struct V_7 * V_68 = V_74 -> V_78 ;
F_46 ( V_75 -> V_79 , V_77 ) ;
V_77 -> V_70 = ( V_68 -> V_41 / 512 ) * F_44 ( V_68 , V_77 -> V_69 ) ;
V_77 -> V_80 = V_68 -> V_41 ;
return 0 ;
}
static int F_47 ( struct V_81 * V_81 , struct V_82 * V_83 )
{
return F_48 ( V_81 , F_30 , V_83 ) ;
}
static int F_49 ( struct V_84 * V_84 , struct V_81 * V_81 )
{
return F_50 ( V_81 , F_30 ) ;
}
int F_51 ( struct V_81 * V_81 , T_4 V_85 , unsigned V_86 )
{
return F_52 ( V_81 , V_85 , V_86 , F_30 ) ;
}
static int F_53 ( struct V_84 * V_84 , struct V_87 * V_88 ,
T_4 V_85 , unsigned V_86 , unsigned V_89 ,
struct V_81 * * V_90 , void * * V_91 )
{
int V_92 ;
V_92 = F_54 ( V_88 , V_85 , V_86 , V_89 , V_90 , F_30 ) ;
if ( F_55 ( V_92 ) ) {
T_4 V_93 = V_88 -> V_94 -> V_63 ;
if ( V_85 + V_86 > V_93 )
F_56 ( V_88 -> V_94 , V_93 ) ;
}
return V_92 ;
}
static T_3 F_57 ( struct V_87 * V_88 , T_3 V_4 )
{
return F_58 ( V_88 , V_4 , F_30 ) ;
}
