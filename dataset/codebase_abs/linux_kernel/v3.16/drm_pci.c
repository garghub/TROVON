T_1 * F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 * V_5 ;
unsigned long V_6 ;
T_2 V_7 ;
if ( V_4 > V_3 )
return NULL ;
V_5 = F_2 ( sizeof( T_1 ) , V_8 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_3 = V_3 ;
V_5 -> V_9 = F_3 ( & V_2 -> V_10 -> V_2 , V_3 , & V_5 -> V_11 , V_8 | V_12 ) ;
if ( V_5 -> V_9 == NULL ) {
F_4 ( V_5 ) ;
return NULL ;
}
memset ( V_5 -> V_9 , 0 , V_3 ) ;
for ( V_6 = ( unsigned long ) V_5 -> V_9 , V_7 = V_3 ;
V_7 > 0 ; V_6 += V_13 , V_7 -= V_13 ) {
F_5 ( F_6 ( ( void * ) V_6 ) ) ;
}
return V_5 ;
}
void F_7 ( struct V_1 * V_2 , T_1 * V_5 )
{
unsigned long V_6 ;
T_2 V_7 ;
if ( V_5 -> V_9 ) {
for ( V_6 = ( unsigned long ) V_5 -> V_9 , V_7 = V_5 -> V_3 ;
V_7 > 0 ; V_6 += V_13 , V_7 -= V_13 ) {
F_8 ( F_6 ( ( void * ) V_6 ) ) ;
}
F_9 ( & V_2 -> V_10 -> V_2 , V_5 -> V_3 , V_5 -> V_9 ,
V_5 -> V_11 ) ;
}
}
void F_10 ( struct V_1 * V_2 , T_1 * V_5 )
{
F_7 ( V_2 , V_5 ) ;
F_4 ( V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
#ifndef F_12
if ( V_2 -> V_14 < 0x10004 )
return 0 ;
#endif
return F_13 ( V_2 -> V_10 -> V_15 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 , V_19 ;
V_17 -> V_20 = 40 ;
V_17 -> V_21 = V_17 -> V_20 ;
V_17 -> V_22 = F_2 ( V_17 -> V_21 , V_8 ) ;
if ( V_17 -> V_22 == NULL )
return - V_23 ;
V_18 = snprintf ( V_17 -> V_22 , V_17 -> V_20 ,
L_1 ,
F_11 ( V_2 ) ,
V_2 -> V_10 -> V_15 -> V_24 ,
F_15 ( V_2 -> V_10 -> V_25 ) ,
F_16 ( V_2 -> V_10 -> V_25 ) ) ;
if ( V_18 >= V_17 -> V_20 ) {
F_17 ( L_2 ) ;
V_19 = - V_26 ;
goto V_27;
} else
V_17 -> V_20 = V_18 ;
return 0 ;
V_27:
return V_19 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_28 * V_29 )
{
int V_30 , V_15 , V_31 , V_32 , V_19 ;
V_17 -> V_20 = V_29 -> V_20 ;
V_17 -> V_21 = V_29 -> V_20 + 1 ;
V_17 -> V_22 = F_2 ( V_17 -> V_21 , V_8 ) ;
if ( ! V_17 -> V_22 ) {
V_19 = - V_23 ;
goto V_27;
}
if ( F_19 ( V_17 -> V_22 , V_29 -> V_22 , V_17 -> V_20 ) ) {
V_19 = - V_33 ;
goto V_27;
}
V_17 -> V_22 [ V_17 -> V_20 ] = '\0' ;
V_19 = sscanf ( V_17 -> V_22 , L_3 , & V_15 , & V_31 , & V_32 ) ;
if ( V_19 != 3 ) {
V_19 = - V_26 ;
goto V_27;
}
V_30 = V_15 >> 8 ;
V_15 &= 0xff ;
if ( ( V_30 != F_11 ( V_2 ) ) ||
( V_15 != V_2 -> V_10 -> V_15 -> V_24 ) ||
( V_31 != F_15 ( V_2 -> V_10 -> V_25 ) ) ||
( V_32 != F_16 ( V_2 -> V_10 -> V_25 ) ) ) {
V_19 = - V_26 ;
goto V_27;
}
return 0 ;
V_27:
return V_19 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
if ( ( V_35 -> V_36 >> 8 ) != F_11 ( V_2 ) ||
( V_35 -> V_36 & 0xff ) != V_2 -> V_10 -> V_15 -> V_24 ||
V_35 -> V_37 != F_15 ( V_2 -> V_10 -> V_25 ) || V_35 -> V_38 != F_16 ( V_2 -> V_10 -> V_25 ) )
return - V_26 ;
V_35 -> V_39 = V_2 -> V_10 -> V_39 ;
F_21 ( L_4 , V_35 -> V_36 , V_35 -> V_37 , V_35 -> V_38 ,
V_35 -> V_39 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , void * V_40 ,
struct V_41 * V_42 )
{
struct V_34 * V_35 = V_40 ;
if ( F_23 ( V_2 , V_43 ) )
return - V_26 ;
if ( F_24 ( ! V_2 -> V_10 ) )
return - V_26 ;
if ( ! F_23 ( V_2 , V_44 ) )
return - V_26 ;
return F_20 ( V_2 , V_35 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 , V_45 ) ) {
if ( F_26 ( V_2 ) )
V_2 -> V_46 = F_27 ( V_2 ) ;
if ( V_2 -> V_46 ) {
V_2 -> V_46 -> V_47 = F_28 (
V_2 -> V_46 -> V_48 . V_49 ,
V_2 -> V_46 -> V_48 . V_50 *
1024 * 1024 ) ;
}
}
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_30 ( V_2 -> V_46 -> V_47 ) ;
F_31 ( V_2 ) ;
F_4 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
}
}
int F_32 ( struct V_51 * V_10 , const struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 ;
int V_19 ;
F_21 ( L_5 ) ;
V_2 = F_33 ( V_55 , & V_10 -> V_2 ) ;
if ( ! V_2 )
return - V_23 ;
V_19 = F_34 ( V_10 ) ;
if ( V_19 )
goto V_56;
V_2 -> V_10 = V_10 ;
#ifdef F_12
V_2 -> V_57 = V_10 -> V_58 ;
#endif
if ( F_23 ( V_2 , V_43 ) )
F_35 ( V_10 , V_2 ) ;
F_25 ( V_2 ) ;
V_19 = F_36 ( V_2 , V_53 -> V_59 ) ;
if ( V_19 )
goto V_60;
F_37 ( L_6 ,
V_55 -> V_61 , V_55 -> V_62 , V_55 -> V_63 , V_55 -> V_64 ,
V_55 -> V_65 , F_38 ( V_10 ) , V_2 -> V_66 -> V_67 ) ;
if ( ! F_23 ( V_2 , V_43 ) )
F_39 ( & V_2 -> V_68 , & V_55 -> V_68 ) ;
return 0 ;
V_60:
F_29 ( V_2 ) ;
F_40 ( V_10 ) ;
V_56:
F_41 ( V_2 ) ;
return V_19 ;
}
int F_42 ( struct V_54 * V_55 , struct V_69 * V_70 )
{
struct V_51 * V_10 = NULL ;
const struct V_52 * V_71 ;
int V_72 ;
F_21 ( L_5 ) ;
V_55 -> V_15 = & V_73 ;
if ( V_55 -> V_74 & V_43 )
return F_43 ( V_70 ) ;
F_44 ( & V_55 -> V_68 ) ;
for ( V_72 = 0 ; V_70 -> V_75 [ V_72 ] . V_76 != 0 ; V_72 ++ ) {
V_71 = & V_70 -> V_75 [ V_72 ] ;
V_10 = NULL ;
while ( ( V_10 =
F_45 ( V_71 -> V_76 , V_71 -> V_77 , V_71 -> V_78 ,
V_71 -> V_79 , V_10 ) ) != NULL ) {
if ( ( V_10 -> V_80 & V_71 -> V_81 ) != V_71 -> V_80 )
continue;
F_46 ( V_10 ) ;
F_32 ( V_10 , V_71 , V_55 ) ;
}
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , T_3 * V_82 )
{
struct V_51 * V_83 ;
T_3 V_84 , V_85 ;
* V_82 = 0 ;
if ( ! V_2 -> V_10 )
return - V_26 ;
V_83 = V_2 -> V_10 -> V_15 -> V_86 ;
if ( V_83 -> V_76 == V_87 ||
V_83 -> V_76 == V_88 )
return - V_26 ;
F_48 ( V_83 , V_89 , & V_84 ) ;
F_48 ( V_83 , V_90 , & V_85 ) ;
if ( V_85 ) {
if ( V_85 & V_91 )
* V_82 |= V_92 ;
if ( V_85 & V_93 )
* V_82 |= V_94 ;
if ( V_85 & V_95 )
* V_82 |= V_96 ;
} else {
if ( V_84 & V_97 )
* V_82 |= V_92 ;
if ( V_84 & V_98 )
* V_82 |= ( V_92 | V_94 ) ;
}
F_37 ( L_7 , V_83 -> V_76 , V_83 -> V_77 , V_84 , V_85 ) ;
return 0 ;
}
int F_42 ( struct V_54 * V_55 , struct V_69 * V_70 )
{
return - 1 ;
}
void F_29 ( struct V_1 * V_2 ) {}
int F_22 ( struct V_1 * V_2 , void * V_40 ,
struct V_41 * V_42 )
{
return - V_26 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_28 * V_29 )
{
return - V_26 ;
}
void F_49 ( struct V_54 * V_55 , struct V_69 * V_70 )
{
struct V_1 * V_2 , * V_99 ;
F_21 ( L_5 ) ;
if ( V_55 -> V_74 & V_43 ) {
F_50 ( V_70 ) ;
} else {
F_51 (dev, tmp, &driver->legacy_dev_list,
legacy_dev_list) {
F_52 ( & V_2 -> V_68 ) ;
F_53 ( V_2 ) ;
}
}
F_37 ( L_8 ) ;
}
