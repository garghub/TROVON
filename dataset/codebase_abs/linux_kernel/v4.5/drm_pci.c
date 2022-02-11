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
int F_14 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
V_17 -> V_18 = F_15 ( V_8 , L_1 ,
F_11 ( V_2 ) ,
V_2 -> V_10 -> V_15 -> V_19 ,
F_16 ( V_2 -> V_10 -> V_20 ) ,
F_17 ( V_2 -> V_10 -> V_20 ) ) ;
if ( ! V_17 -> V_18 )
return - V_21 ;
V_17 -> V_22 = strlen ( V_17 -> V_18 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_23 * V_24 )
{
int V_25 , V_15 , V_26 , V_27 , V_28 ;
V_17 -> V_22 = V_24 -> V_22 ;
V_17 -> V_18 = F_2 ( V_17 -> V_22 + 1 , V_8 ) ;
if ( ! V_17 -> V_18 ) {
V_28 = - V_21 ;
goto V_29;
}
if ( F_19 ( V_17 -> V_18 , V_24 -> V_18 , V_17 -> V_22 ) ) {
V_28 = - V_30 ;
goto V_29;
}
V_17 -> V_18 [ V_17 -> V_22 ] = '\0' ;
V_28 = sscanf ( V_17 -> V_18 , L_2 , & V_15 , & V_26 , & V_27 ) ;
if ( V_28 != 3 ) {
V_28 = - V_31 ;
goto V_29;
}
V_25 = V_15 >> 8 ;
V_15 &= 0xff ;
if ( ( V_25 != F_11 ( V_2 ) ) ||
( V_15 != V_2 -> V_10 -> V_15 -> V_19 ) ||
( V_26 != F_16 ( V_2 -> V_10 -> V_20 ) ) ||
( V_27 != F_17 ( V_2 -> V_10 -> V_20 ) ) ) {
V_28 = - V_31 ;
goto V_29;
}
return 0 ;
V_29:
return V_28 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
if ( ( V_33 -> V_34 >> 8 ) != F_11 ( V_2 ) ||
( V_33 -> V_34 & 0xff ) != V_2 -> V_10 -> V_15 -> V_19 ||
V_33 -> V_35 != F_16 ( V_2 -> V_10 -> V_20 ) || V_33 -> V_36 != F_17 ( V_2 -> V_10 -> V_20 ) )
return - V_31 ;
V_33 -> V_37 = V_2 -> V_10 -> V_37 ;
F_21 ( L_3 , V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 ,
V_33 -> V_37 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , void * V_38 ,
struct V_39 * V_40 )
{
struct V_32 * V_33 = V_38 ;
if ( F_23 ( V_2 , V_41 ) )
return - V_31 ;
if ( F_24 ( ! V_2 -> V_10 ) )
return - V_31 ;
if ( ! F_23 ( V_2 , V_42 ) )
return - V_31 ;
return F_20 ( V_2 , V_33 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 , V_43 ) ) {
if ( F_26 ( V_2 ) )
V_2 -> V_44 = F_27 ( V_2 ) ;
if ( V_2 -> V_44 ) {
V_2 -> V_44 -> V_45 = F_28 (
V_2 -> V_44 -> V_46 . V_47 ,
V_2 -> V_44 -> V_46 . V_48 *
1024 * 1024 ) ;
}
}
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 ) {
F_30 ( V_2 -> V_44 -> V_45 ) ;
F_31 ( V_2 ) ;
F_4 ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
}
}
int F_32 ( struct V_49 * V_10 , const struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 ;
int V_28 ;
F_21 ( L_4 ) ;
V_2 = F_33 ( V_53 , & V_10 -> V_2 ) ;
if ( ! V_2 )
return - V_21 ;
V_28 = F_34 ( V_10 ) ;
if ( V_28 )
goto V_54;
V_2 -> V_10 = V_10 ;
#ifdef F_12
V_2 -> V_55 = V_10 -> V_56 ;
#endif
if ( F_23 ( V_2 , V_41 ) )
F_35 ( V_10 , V_2 ) ;
F_25 ( V_2 ) ;
V_28 = F_36 ( V_2 , V_51 -> V_57 ) ;
if ( V_28 )
goto V_58;
F_37 ( L_5 ,
V_53 -> V_59 , V_53 -> V_60 , V_53 -> V_61 , V_53 -> V_62 ,
V_53 -> V_63 , F_38 ( V_10 ) , V_2 -> V_64 -> V_65 ) ;
if ( ! F_23 ( V_2 , V_41 ) )
F_39 ( & V_2 -> V_66 , & V_53 -> V_66 ) ;
return 0 ;
V_58:
F_29 ( V_2 ) ;
F_40 ( V_10 ) ;
V_54:
F_41 ( V_2 ) ;
return V_28 ;
}
int F_42 ( struct V_52 * V_53 , struct V_67 * V_68 )
{
struct V_49 * V_10 = NULL ;
const struct V_50 * V_69 ;
int V_70 ;
F_21 ( L_4 ) ;
if ( V_53 -> V_71 & V_41 )
return F_43 ( V_68 ) ;
F_44 ( & V_53 -> V_66 ) ;
for ( V_70 = 0 ; V_68 -> V_72 [ V_70 ] . V_73 != 0 ; V_70 ++ ) {
V_69 = & V_68 -> V_72 [ V_70 ] ;
V_10 = NULL ;
while ( ( V_10 =
F_45 ( V_69 -> V_73 , V_69 -> V_74 , V_69 -> V_75 ,
V_69 -> V_76 , V_10 ) ) != NULL ) {
if ( ( V_10 -> V_77 & V_69 -> V_78 ) != V_69 -> V_77 )
continue;
F_46 ( V_10 ) ;
F_32 ( V_10 , V_69 , V_53 ) ;
}
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , T_3 * V_79 )
{
struct V_49 * V_80 ;
T_3 V_81 , V_82 ;
* V_79 = 0 ;
if ( ! V_2 -> V_10 )
return - V_31 ;
V_80 = V_2 -> V_10 -> V_15 -> V_83 ;
if ( V_80 -> V_73 == V_84 ||
V_80 -> V_73 == V_85 )
return - V_31 ;
F_48 ( V_80 , V_86 , & V_81 ) ;
F_48 ( V_80 , V_87 , & V_82 ) ;
if ( V_82 ) {
if ( V_82 & V_88 )
* V_79 |= V_89 ;
if ( V_82 & V_90 )
* V_79 |= V_91 ;
if ( V_82 & V_92 )
* V_79 |= V_93 ;
} else {
if ( V_81 & V_94 )
* V_79 |= V_89 ;
if ( V_81 & V_95 )
* V_79 |= ( V_89 | V_91 ) ;
}
F_37 ( L_6 , V_80 -> V_73 , V_80 -> V_74 , V_81 , V_82 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , T_3 * V_96 )
{
struct V_49 * V_80 ;
T_3 V_81 ;
* V_96 = 0 ;
if ( ! V_2 -> V_10 )
return - V_31 ;
V_80 = V_2 -> V_10 -> V_15 -> V_83 ;
F_48 ( V_80 , V_86 , & V_81 ) ;
* V_96 = ( V_81 & V_97 ) >> 4 ;
F_37 ( L_7 , V_80 -> V_73 , V_80 -> V_74 , V_81 ) ;
return 0 ;
}
int F_42 ( struct V_52 * V_53 , struct V_67 * V_68 )
{
return - 1 ;
}
void F_29 ( struct V_1 * V_2 ) {}
int F_22 ( struct V_1 * V_2 , void * V_38 ,
struct V_39 * V_40 )
{
return - V_31 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_23 * V_24 )
{
return - V_31 ;
}
void F_50 ( struct V_52 * V_53 , struct V_67 * V_68 )
{
struct V_1 * V_2 , * V_98 ;
F_21 ( L_4 ) ;
if ( V_53 -> V_71 & V_41 ) {
F_51 ( V_68 ) ;
} else {
F_52 (dev, tmp, &driver->legacy_dev_list,
legacy_dev_list) {
F_53 ( & V_2 -> V_66 ) ;
F_54 ( V_2 ) ;
}
}
F_37 ( L_8 ) ;
}
