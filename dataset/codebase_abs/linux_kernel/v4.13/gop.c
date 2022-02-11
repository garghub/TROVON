static void F_1 ( unsigned long V_1 , T_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 , V_5 ;
V_4 = 0 ;
V_5 = 0 ;
if ( V_1 ) {
while ( ! ( V_1 & 0x1 ) ) {
V_1 = V_1 >> 1 ;
V_4 ++ ;
}
while ( V_1 & 0x1 ) {
V_1 = V_1 >> 1 ;
V_5 ++ ;
}
}
* V_2 = V_4 ;
* V_3 = V_5 ;
}
static void
F_2 ( struct V_6 * V_7 , T_2 V_8 ,
struct V_9 V_10 , int V_11 )
{
if ( V_11 == V_12 ) {
V_7 -> V_13 = 32 ;
V_7 -> V_14 = V_8 * 4 ;
V_7 -> V_15 = 8 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 8 ;
V_7 -> V_18 = 8 ;
V_7 -> V_19 = 8 ;
V_7 -> V_20 = 16 ;
V_7 -> V_21 = 8 ;
V_7 -> V_22 = 24 ;
} else if ( V_11 == V_23 ) {
V_7 -> V_13 = 32 ;
V_7 -> V_14 = V_8 * 4 ;
V_7 -> V_15 = 8 ;
V_7 -> V_16 = 16 ;
V_7 -> V_17 = 8 ;
V_7 -> V_18 = 8 ;
V_7 -> V_19 = 8 ;
V_7 -> V_20 = 0 ;
V_7 -> V_21 = 8 ;
V_7 -> V_22 = 24 ;
} else if ( V_11 == V_24 ) {
F_1 ( V_10 . V_25 , & V_7 -> V_16 , & V_7 -> V_15 ) ;
F_1 ( V_10 . V_26 , & V_7 -> V_18 ,
& V_7 -> V_17 ) ;
F_1 ( V_10 . V_27 , & V_7 -> V_20 , & V_7 -> V_19 ) ;
F_1 ( V_10 . V_28 , & V_7 -> V_22 ,
& V_7 -> V_21 ) ;
V_7 -> V_13 = V_7 -> V_15 + V_7 -> V_17 +
V_7 -> V_19 + V_7 -> V_21 ;
V_7 -> V_14 = ( V_8 * V_7 -> V_13 ) / 8 ;
} else {
V_7 -> V_13 = 4 ;
V_7 -> V_14 = V_7 -> V_29 / 2 ;
V_7 -> V_15 = 0 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_18 = 0 ;
V_7 -> V_19 = 0 ;
V_7 -> V_20 = 0 ;
V_7 -> V_21 = 0 ;
V_7 -> V_22 = 0 ;
}
}
static T_3
F_3 ( T_4 * V_30 ,
struct V_31 * V_32 ,
struct V_33 * * V_34 ,
unsigned long * V_3 , T_5 * V_35 )
{
struct V_36 * V_37 ;
T_6 V_38 ;
T_3 V_39 ;
unsigned long V_40 ;
V_40 = V_32 -> V_37 ;
V_37 = (struct V_36 * ) V_40 ;
V_38 = ( void * ) ( unsigned long ) V_32 -> V_38 ;
V_39 = F_4 ( V_38 , ( void * ) V_32 , V_37 -> V_37 , V_3 ,
V_34 ) ;
if ( V_39 != V_41 )
return V_39 ;
* V_35 = V_37 -> V_42 ;
return V_39 ;
}
static T_3
F_5 ( T_4 * V_30 , struct V_6 * V_7 ,
T_7 * V_43 , unsigned long V_3 , void * * V_44 )
{
struct V_31 * V_32 , * V_45 ;
unsigned long V_46 ;
T_8 V_47 , V_48 ;
T_2 V_8 ;
T_2 V_49 ;
T_5 V_35 ;
struct V_9 V_10 ;
int V_11 ;
T_3 V_39 = V_50 ;
T_2 * V_51 = ( T_2 * ) ( unsigned long ) V_44 ;
int V_52 ;
V_45 = NULL ;
V_32 = NULL ;
V_46 = V_3 / sizeof( T_2 ) ;
for ( V_52 = 0 ; V_52 < V_46 ; V_52 ++ ) {
struct V_33 * V_34 = NULL ;
T_7 V_53 = V_54 ;
bool V_55 = false ;
void * V_56 = NULL ;
T_9 V_57 = ( T_9 ) ( unsigned long ) V_51 [ V_52 ] ;
T_5 V_58 ;
V_39 = F_6 ( V_59 , V_57 ,
V_43 , ( void * * ) & V_32 ) ;
if ( V_39 != V_41 )
continue;
V_39 = F_6 ( V_59 , V_57 ,
& V_53 , & V_56 ) ;
if ( V_39 == V_41 )
V_55 = true ;
V_39 = F_3 ( V_30 , V_32 , & V_34 , & V_3 ,
& V_58 ) ;
if ( V_39 == V_41 && ( ! V_45 || V_55 ) &&
V_34 -> V_11 != V_60 ) {
V_47 = V_34 -> V_61 ;
V_48 = V_34 -> V_62 ;
V_11 = V_34 -> V_11 ;
V_10 = V_34 -> V_63 ;
V_8 = V_34 -> V_8 ;
V_35 = V_58 ;
V_45 = V_32 ;
if ( V_55 )
break;
}
}
if ( ! V_45 )
goto V_64;
V_7 -> V_65 = V_66 ;
V_7 -> V_29 = V_47 ;
V_7 -> V_67 = V_48 ;
V_7 -> V_68 = V_35 ;
V_49 = ( T_5 ) ( unsigned long ) V_35 >> 32 ;
if ( V_49 ) {
V_7 -> V_69 |= V_70 ;
V_7 -> V_49 = V_49 ;
}
V_7 -> V_71 = 1 ;
F_2 ( V_7 , V_8 , V_10 , V_11 ) ;
V_7 -> V_72 = V_7 -> V_14 * V_7 -> V_67 ;
V_7 -> V_69 |= V_73 ;
V_64:
return V_39 ;
}
static T_3
F_7 ( T_4 * V_30 ,
struct V_74 * V_75 ,
struct V_33 * * V_34 ,
unsigned long * V_3 , T_5 * V_35 )
{
struct V_76 * V_37 ;
T_6 V_38 ;
T_3 V_39 ;
unsigned long V_40 ;
V_40 = V_75 -> V_37 ;
V_37 = (struct V_76 * ) V_40 ;
V_38 = ( void * ) ( unsigned long ) V_75 -> V_38 ;
V_39 = F_4 ( V_38 , ( void * ) V_75 , V_37 -> V_37 , V_3 ,
V_34 ) ;
if ( V_39 != V_41 )
return V_39 ;
* V_35 = V_37 -> V_42 ;
return V_39 ;
}
static T_3
F_8 ( T_4 * V_30 , struct V_6 * V_7 ,
T_7 * V_43 , unsigned long V_3 , void * * V_44 )
{
struct V_74 * V_75 , * V_45 ;
unsigned long V_46 ;
T_8 V_47 , V_48 ;
T_2 V_8 ;
T_2 V_49 ;
T_5 V_35 ;
struct V_9 V_10 ;
int V_11 ;
T_3 V_39 = V_50 ;
T_5 * V_51 = ( T_5 * ) ( unsigned long ) V_44 ;
int V_52 ;
V_45 = NULL ;
V_75 = NULL ;
V_46 = V_3 / sizeof( T_5 ) ;
for ( V_52 = 0 ; V_52 < V_46 ; V_52 ++ ) {
struct V_33 * V_34 = NULL ;
T_7 V_53 = V_54 ;
bool V_55 = false ;
void * V_56 = NULL ;
T_9 V_57 = ( T_9 ) ( unsigned long ) V_51 [ V_52 ] ;
T_5 V_58 ;
V_39 = F_6 ( V_59 , V_57 ,
V_43 , ( void * * ) & V_75 ) ;
if ( V_39 != V_41 )
continue;
V_39 = F_6 ( V_59 , V_57 ,
& V_53 , & V_56 ) ;
if ( V_39 == V_41 )
V_55 = true ;
V_39 = F_7 ( V_30 , V_75 , & V_34 , & V_3 ,
& V_58 ) ;
if ( V_39 == V_41 && ( ! V_45 || V_55 ) &&
V_34 -> V_11 != V_60 ) {
V_47 = V_34 -> V_61 ;
V_48 = V_34 -> V_62 ;
V_11 = V_34 -> V_11 ;
V_10 = V_34 -> V_63 ;
V_8 = V_34 -> V_8 ;
V_35 = V_58 ;
V_45 = V_75 ;
if ( V_55 )
break;
}
}
if ( ! V_45 )
goto V_64;
V_7 -> V_65 = V_66 ;
V_7 -> V_29 = V_47 ;
V_7 -> V_67 = V_48 ;
V_7 -> V_68 = V_35 ;
V_49 = ( T_5 ) ( unsigned long ) V_35 >> 32 ;
if ( V_49 ) {
V_7 -> V_69 |= V_70 ;
V_7 -> V_49 = V_49 ;
}
V_7 -> V_71 = 1 ;
F_2 ( V_7 , V_8 , V_10 , V_11 ) ;
V_7 -> V_72 = V_7 -> V_14 * V_7 -> V_67 ;
V_7 -> V_69 |= V_73 ;
V_64:
return V_39 ;
}
T_3 F_9 ( T_4 * V_30 ,
struct V_6 * V_7 , T_7 * V_43 ,
unsigned long V_3 )
{
T_3 V_39 ;
void * * V_44 = NULL ;
V_39 = F_6 ( V_77 , V_78 ,
V_3 , ( void * * ) & V_44 ) ;
if ( V_39 != V_41 )
return V_39 ;
V_39 = F_6 ( V_79 ,
V_80 ,
V_43 , NULL , & V_3 , V_44 ) ;
if ( V_39 != V_41 )
goto V_81;
if ( F_10 () ) {
V_39 = F_8 ( V_30 , V_7 , V_43 , V_3 ,
V_44 ) ;
} else {
V_39 = F_5 ( V_30 , V_7 , V_43 , V_3 ,
V_44 ) ;
}
V_81:
F_6 ( V_82 , V_44 ) ;
return V_39 ;
}
