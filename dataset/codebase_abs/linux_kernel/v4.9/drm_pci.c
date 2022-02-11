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
static int F_18 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
if ( ( V_24 -> V_25 >> 8 ) != F_11 ( V_2 ) ||
( V_24 -> V_25 & 0xff ) != V_2 -> V_10 -> V_15 -> V_19 ||
V_24 -> V_26 != F_16 ( V_2 -> V_10 -> V_20 ) || V_24 -> V_27 != F_17 ( V_2 -> V_10 -> V_20 ) )
return - V_28 ;
V_24 -> V_29 = V_2 -> V_10 -> V_29 ;
F_19 ( L_2 , V_24 -> V_25 , V_24 -> V_26 , V_24 -> V_27 ,
V_24 -> V_29 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_23 * V_24 = V_30 ;
if ( ! F_21 ( V_2 , V_33 ) )
return - V_28 ;
if ( F_22 ( ! V_2 -> V_10 ) )
return - V_28 ;
if ( ! F_21 ( V_2 , V_34 ) )
return - V_28 ;
return F_18 ( V_2 , V_24 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( F_21 ( V_2 , V_35 ) ) {
if ( F_24 ( V_2 ) )
V_2 -> V_36 = F_25 ( V_2 ) ;
if ( V_2 -> V_36 ) {
V_2 -> V_36 -> V_37 = F_26 (
V_2 -> V_36 -> V_38 . V_39 ,
V_2 -> V_36 -> V_38 . V_40 *
1024 * 1024 ) ;
}
}
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 ) {
F_28 ( V_2 -> V_36 -> V_37 ) ;
F_29 ( V_2 ) ;
F_4 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
}
int F_30 ( struct V_41 * V_10 , const struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_46 ;
F_19 ( L_3 ) ;
V_2 = F_31 ( V_45 , & V_10 -> V_2 ) ;
if ( F_32 ( V_2 ) )
return F_33 ( V_2 ) ;
V_46 = F_34 ( V_10 ) ;
if ( V_46 )
goto V_47;
V_2 -> V_10 = V_10 ;
#ifdef F_12
V_2 -> V_48 = V_10 -> V_49 ;
#endif
if ( F_21 ( V_2 , V_50 ) )
F_35 ( V_10 , V_2 ) ;
F_23 ( V_2 ) ;
V_46 = F_36 ( V_2 , V_43 -> V_51 ) ;
if ( V_46 )
goto V_52;
F_37 ( L_4 ,
V_45 -> V_53 , V_45 -> V_54 , V_45 -> V_55 , V_45 -> V_56 ,
V_45 -> V_57 , F_38 ( V_10 ) , V_2 -> V_58 -> V_59 ) ;
if ( F_21 ( V_2 , V_33 ) )
F_39 ( & V_2 -> V_60 , & V_45 -> V_60 ) ;
return 0 ;
V_52:
F_27 ( V_2 ) ;
F_40 ( V_10 ) ;
V_47:
F_41 ( V_2 ) ;
return V_46 ;
}
int F_42 ( struct V_44 * V_45 , struct V_61 * V_62 )
{
struct V_41 * V_10 = NULL ;
const struct V_42 * V_63 ;
int V_64 ;
F_19 ( L_3 ) ;
if ( ! ( V_45 -> V_65 & V_33 ) )
return F_43 ( V_62 ) ;
F_44 ( & V_45 -> V_60 ) ;
for ( V_64 = 0 ; V_62 -> V_66 [ V_64 ] . V_67 != 0 ; V_64 ++ ) {
V_63 = & V_62 -> V_66 [ V_64 ] ;
V_10 = NULL ;
while ( ( V_10 =
F_45 ( V_63 -> V_67 , V_63 -> V_68 , V_63 -> V_69 ,
V_63 -> V_70 , V_10 ) ) != NULL ) {
if ( ( V_10 -> V_71 & V_63 -> V_72 ) != V_63 -> V_71 )
continue;
F_46 ( V_10 ) ;
F_30 ( V_10 , V_63 , V_45 ) ;
}
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , T_3 * V_73 )
{
struct V_41 * V_74 ;
T_3 V_75 , V_76 ;
* V_73 = 0 ;
if ( ! V_2 -> V_10 )
return - V_28 ;
V_74 = V_2 -> V_10 -> V_15 -> V_77 ;
if ( V_74 -> V_67 == V_78 ||
V_74 -> V_67 == V_79 )
return - V_28 ;
F_48 ( V_74 , V_80 , & V_75 ) ;
F_48 ( V_74 , V_81 , & V_76 ) ;
if ( V_76 ) {
if ( V_76 & V_82 )
* V_73 |= V_83 ;
if ( V_76 & V_84 )
* V_73 |= V_85 ;
if ( V_76 & V_86 )
* V_73 |= V_87 ;
} else {
if ( V_75 & V_88 )
* V_73 |= V_83 ;
if ( V_75 & V_89 )
* V_73 |= ( V_83 | V_85 ) ;
}
F_37 ( L_5 , V_74 -> V_67 , V_74 -> V_68 , V_75 , V_76 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , T_3 * V_90 )
{
struct V_41 * V_74 ;
T_3 V_75 ;
* V_90 = 0 ;
if ( ! V_2 -> V_10 )
return - V_28 ;
V_74 = V_2 -> V_10 -> V_15 -> V_77 ;
F_48 ( V_74 , V_80 , & V_75 ) ;
* V_90 = ( V_75 & V_91 ) >> 4 ;
F_37 ( L_6 , V_74 -> V_67 , V_74 -> V_68 , V_75 ) ;
return 0 ;
}
int F_42 ( struct V_44 * V_45 , struct V_61 * V_62 )
{
return - 1 ;
}
void F_27 ( struct V_1 * V_2 ) {}
int F_20 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
return - V_28 ;
}
void F_50 ( struct V_44 * V_45 , struct V_61 * V_62 )
{
struct V_1 * V_2 , * V_92 ;
F_19 ( L_3 ) ;
if ( ! ( V_45 -> V_65 & V_33 ) ) {
F_51 ( V_62 ) ;
} else {
F_52 (dev, tmp, &driver->legacy_dev_list,
legacy_dev_list) {
F_53 ( & V_2 -> V_60 ) ;
F_54 ( V_2 ) ;
}
}
F_37 ( L_7 ) ;
}
