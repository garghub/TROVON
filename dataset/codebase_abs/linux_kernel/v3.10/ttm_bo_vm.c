static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 . V_6 ;
unsigned long V_9 ;
struct V_1 * V_10 ;
struct V_1 * V_11 = NULL ;
while ( F_2 ( V_7 != NULL ) ) {
V_10 = F_3 ( V_7 , struct V_1 , V_12 ) ;
V_9 = V_10 -> V_13 -> V_14 ;
if ( V_4 >= V_9 ) {
V_7 = V_7 -> V_15 ;
V_11 = V_10 ;
if ( V_4 == V_9 )
break;
} else
V_7 = V_7 -> V_16 ;
}
if ( F_4 ( V_11 == NULL ) )
return NULL ;
if ( F_4 ( ( V_11 -> V_13 -> V_14 + V_11 -> V_5 ) <
( V_4 + V_5 ) ) )
return NULL ;
return V_11 ;
}
static int F_5 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_10 = (struct V_1 * )
V_18 -> V_21 ;
struct V_2 * V_3 = V_10 -> V_3 ;
unsigned long V_22 ;
unsigned long V_23 ;
unsigned long V_24 ;
struct V_25 * V_26 = NULL ;
struct V_27 * V_27 ;
int V_28 ;
int V_29 ;
unsigned long V_30 = ( unsigned long ) V_20 -> V_31 ;
int V_32 = V_33 ;
struct V_34 * V_35 =
& V_3 -> V_35 [ V_10 -> V_36 . V_37 ] ;
V_28 = F_6 ( V_10 , true , true , false , 0 ) ;
if ( F_4 ( V_28 != 0 ) ) {
if ( V_28 == - V_38 )
F_7 () ;
return V_33 ;
}
if ( V_3 -> V_39 -> V_40 ) {
V_28 = V_3 -> V_39 -> V_40 ( V_10 ) ;
switch ( V_28 ) {
case 0 :
break;
case - V_38 :
F_7 () ;
case - V_41 :
V_32 = V_33 ;
goto V_42;
default:
V_32 = V_43 ;
goto V_42;
}
}
F_8 ( & V_3 -> V_44 ) ;
if ( F_9 ( V_45 , & V_10 -> V_46 ) ) {
V_28 = F_10 ( V_10 , false , true , false ) ;
F_11 ( & V_3 -> V_44 ) ;
if ( F_4 ( V_28 != 0 ) ) {
V_32 = ( V_28 != - V_41 ) ?
V_43 : V_33 ;
goto V_42;
}
} else
F_11 ( & V_3 -> V_44 ) ;
V_28 = F_12 ( V_35 , true ) ;
if ( F_4 ( V_28 != 0 ) ) {
V_32 = V_33 ;
goto V_42;
}
V_28 = F_13 ( V_10 ) ;
if ( F_4 ( V_28 != 0 ) ) {
V_32 = V_43 ;
goto V_47;
}
V_22 = ( ( V_30 - V_18 -> V_48 ) >> V_49 ) +
V_10 -> V_13 -> V_14 - V_18 -> V_50 ;
V_23 = F_14 ( V_18 ) +
V_10 -> V_13 -> V_14 - V_18 -> V_50 ;
if ( F_4 ( V_22 >= V_10 -> V_5 ) ) {
V_32 = V_43 ;
goto V_47;
}
if ( V_10 -> V_36 . V_51 . V_52 ) {
V_18 -> V_53 = F_15 ( V_10 -> V_36 . V_54 ,
V_18 -> V_53 ) ;
} else {
V_26 = V_10 -> V_26 ;
V_18 -> V_53 = ( V_10 -> V_36 . V_54 & V_55 ) ?
F_16 ( V_18 -> V_56 ) :
F_15 ( V_10 -> V_36 . V_54 , V_18 -> V_53 ) ;
if ( V_26 -> V_3 -> V_39 -> V_57 ( V_26 ) ) {
V_32 = V_58 ;
goto V_47;
}
}
for ( V_29 = 0 ; V_29 < V_59 ; ++ V_29 ) {
if ( V_10 -> V_36 . V_51 . V_52 )
V_24 = ( ( V_10 -> V_36 . V_51 . V_60 + V_10 -> V_36 . V_51 . V_61 ) >> V_49 ) + V_22 ;
else {
V_27 = V_26 -> V_62 [ V_22 ] ;
if ( F_4 ( ! V_27 && V_29 == 0 ) ) {
V_32 = V_58 ;
goto V_47;
} else if ( F_4 ( ! V_27 ) ) {
break;
}
V_24 = F_17 ( V_27 ) ;
}
V_28 = F_18 ( V_18 , V_30 , V_24 ) ;
if ( F_4 ( ( V_28 == - V_38 ) || ( V_28 != 0 && V_29 > 0 ) ) )
break;
else if ( F_4 ( V_28 != 0 ) ) {
V_32 =
( V_28 == - V_63 ) ? V_58 : V_43 ;
goto V_47;
}
V_30 += V_64 ;
if ( F_4 ( ++ V_22 >= V_23 ) )
break;
}
V_47:
F_19 ( V_35 ) ;
V_42:
F_20 ( V_10 ) ;
return V_32 ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_1 * V_10 =
(struct V_1 * ) V_18 -> V_21 ;
( void ) F_22 ( V_10 ) ;
}
static void F_23 ( struct V_17 * V_18 )
{
struct V_1 * V_10 = (struct V_1 * ) V_18 -> V_21 ;
F_24 ( & V_10 ) ;
V_18 -> V_21 = NULL ;
}
int F_25 ( struct V_65 * V_66 , struct V_17 * V_18 ,
struct V_2 * V_3 )
{
struct V_67 * V_39 ;
struct V_1 * V_10 ;
int V_28 ;
F_26 ( & V_3 -> V_68 ) ;
V_10 = F_1 ( V_3 , V_18 -> V_50 ,
F_14 ( V_18 ) ) ;
if ( F_2 ( V_10 != NULL ) && ! F_27 ( & V_10 -> V_69 ) )
V_10 = NULL ;
F_28 ( & V_3 -> V_68 ) ;
if ( F_4 ( V_10 == NULL ) ) {
F_29 ( L_1 ) ;
return - V_70 ;
}
V_39 = V_10 -> V_3 -> V_39 ;
if ( F_4 ( ! V_39 -> V_71 ) ) {
V_28 = - V_72 ;
goto V_73;
}
V_28 = V_39 -> V_71 ( V_10 , V_66 ) ;
if ( F_4 ( V_28 != 0 ) )
goto V_73;
V_18 -> V_74 = & V_75 ;
V_18 -> V_21 = V_10 ;
V_18 -> V_56 |= V_76 | V_77 | V_78 | V_79 ;
return 0 ;
V_73:
F_24 ( & V_10 ) ;
return V_28 ;
}
int F_30 ( struct V_17 * V_18 , struct V_1 * V_10 )
{
if ( V_18 -> V_50 != 0 )
return - V_80 ;
V_18 -> V_74 = & V_75 ;
V_18 -> V_21 = F_22 ( V_10 ) ;
V_18 -> V_56 |= V_76 | V_77 | V_78 ;
return 0 ;
}
T_1 F_31 ( struct V_2 * V_3 , struct V_65 * V_66 ,
const char T_2 * V_81 , char T_2 * V_82 , T_3 V_83 ,
T_4 * V_84 , bool V_85 )
{
struct V_1 * V_10 ;
struct V_67 * V_39 ;
struct V_86 V_87 ;
unsigned long V_88 = ( * V_84 >> V_49 ) ;
unsigned long V_89 ;
unsigned long V_90 ;
unsigned long V_91 ;
T_3 V_92 ;
unsigned int V_22 ;
char * V_93 ;
int V_28 ;
bool V_94 = false ;
bool V_95 ;
F_26 ( & V_3 -> V_68 ) ;
V_10 = F_1 ( V_3 , V_88 , 1 ) ;
if ( F_2 ( V_10 != NULL ) )
F_22 ( V_10 ) ;
F_28 ( & V_3 -> V_68 ) ;
if ( F_4 ( V_10 == NULL ) )
return - V_96 ;
V_39 = V_10 -> V_3 -> V_39 ;
if ( F_4 ( ! V_39 -> V_71 ) ) {
V_28 = - V_72 ;
goto V_73;
}
V_28 = V_39 -> V_71 ( V_10 , V_66 ) ;
if ( F_4 ( V_28 != 0 ) )
goto V_73;
V_89 = V_88 - V_10 -> V_13 -> V_14 ;
if ( F_4 ( V_89 >= V_10 -> V_5 ) ) {
V_28 = - V_97 ;
goto V_73;
}
V_22 = * V_84 & ~ V_98 ;
V_92 = V_10 -> V_5 - V_89 ;
V_92 = ( V_92 << V_49 ) - V_22 ;
if ( V_83 < V_92 )
V_92 = V_83 ;
V_90 = ( * V_84 + V_83 - 1 ) >> V_49 ;
V_91 = V_90 - V_89 + 1 ;
V_28 = F_6 ( V_10 , true , V_94 , false , 0 ) ;
switch ( V_28 ) {
case 0 :
break;
case - V_38 :
V_28 = - V_99 ;
goto V_73;
default:
goto V_73;
}
V_28 = F_32 ( V_10 , V_89 , V_91 , & V_87 ) ;
if ( F_4 ( V_28 != 0 ) ) {
F_20 ( V_10 ) ;
goto V_73;
}
V_93 = F_33 ( & V_87 , & V_95 ) ;
V_93 += V_22 ;
if ( V_85 )
V_28 = F_34 ( V_93 , V_81 , V_92 ) ;
else
V_28 = F_35 ( V_82 , V_93 , V_92 ) ;
F_36 ( & V_87 ) ;
F_20 ( V_10 ) ;
F_24 ( & V_10 ) ;
if ( F_4 ( V_28 != 0 ) )
return - V_97 ;
* V_84 += V_92 ;
return V_92 ;
V_73:
F_24 ( & V_10 ) ;
return V_28 ;
}
T_1 F_37 ( struct V_1 * V_10 , const char T_2 * V_81 ,
char T_2 * V_82 , T_3 V_83 , T_4 * V_84 ,
bool V_85 )
{
struct V_86 V_87 ;
unsigned long V_89 ;
unsigned long V_90 ;
unsigned long V_91 ;
T_3 V_92 ;
unsigned int V_22 ;
char * V_93 ;
int V_28 ;
bool V_94 = false ;
bool V_95 ;
V_89 = ( * V_84 >> V_49 ) ;
if ( F_4 ( V_89 >= V_10 -> V_5 ) )
return - V_97 ;
V_22 = * V_84 & ~ V_98 ;
V_92 = V_10 -> V_5 - V_89 ;
V_92 = ( V_92 << V_49 ) - V_22 ;
if ( V_83 < V_92 )
V_92 = V_83 ;
V_90 = ( * V_84 + V_83 - 1 ) >> V_49 ;
V_91 = V_90 - V_89 + 1 ;
V_28 = F_6 ( V_10 , true , V_94 , false , 0 ) ;
switch ( V_28 ) {
case 0 :
break;
case - V_38 :
return - V_99 ;
default:
return V_28 ;
}
V_28 = F_32 ( V_10 , V_89 , V_91 , & V_87 ) ;
if ( F_4 ( V_28 != 0 ) ) {
F_20 ( V_10 ) ;
return V_28 ;
}
V_93 = F_33 ( & V_87 , & V_95 ) ;
V_93 += V_22 ;
if ( V_85 )
V_28 = F_34 ( V_93 , V_81 , V_92 ) ;
else
V_28 = F_35 ( V_82 , V_93 , V_92 ) ;
F_36 ( & V_87 ) ;
F_20 ( V_10 ) ;
F_24 ( & V_10 ) ;
if ( F_4 ( V_28 != 0 ) )
return V_28 ;
* V_84 += V_92 ;
return V_92 ;
}
