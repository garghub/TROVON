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
if ( F_24 ( V_2 -> V_10 , V_36 ) )
V_2 -> V_37 = F_25 ( V_2 ) ;
if ( V_2 -> V_37 ) {
V_2 -> V_37 -> V_38 = F_26 (
V_2 -> V_37 -> V_39 . V_40 ,
V_2 -> V_37 -> V_39 . V_41 *
1024 * 1024 ) ;
}
}
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 ) {
F_28 ( V_2 -> V_37 -> V_38 ) ;
F_29 ( V_2 ) ;
F_4 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
}
int F_30 ( struct V_42 * V_10 , const struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 ;
int V_47 ;
F_19 ( L_3 ) ;
V_2 = F_31 ( V_46 , & V_10 -> V_2 ) ;
if ( F_32 ( V_2 ) )
return F_33 ( V_2 ) ;
V_47 = F_34 ( V_10 ) ;
if ( V_47 )
goto V_48;
V_2 -> V_10 = V_10 ;
#ifdef F_12
V_2 -> V_49 = V_10 -> V_50 ;
#endif
if ( F_21 ( V_2 , V_51 ) )
F_35 ( V_10 , V_2 ) ;
F_23 ( V_2 ) ;
V_47 = F_36 ( V_2 , V_44 -> V_52 ) ;
if ( V_47 )
goto V_53;
if ( F_21 ( V_2 , V_33 ) )
F_37 ( & V_2 -> V_54 , & V_46 -> V_54 ) ;
return 0 ;
V_53:
F_27 ( V_2 ) ;
F_38 ( V_10 ) ;
V_48:
F_39 ( V_2 ) ;
return V_47 ;
}
int F_40 ( struct V_45 * V_46 , struct V_55 * V_56 )
{
struct V_42 * V_10 = NULL ;
const struct V_43 * V_57 ;
int V_58 ;
F_19 ( L_3 ) ;
if ( ! ( V_46 -> V_59 & V_33 ) )
return F_41 ( V_56 ) ;
F_42 ( & V_46 -> V_54 ) ;
for ( V_58 = 0 ; V_56 -> V_60 [ V_58 ] . V_61 != 0 ; V_58 ++ ) {
V_57 = & V_56 -> V_60 [ V_58 ] ;
V_10 = NULL ;
while ( ( V_10 =
F_43 ( V_57 -> V_61 , V_57 -> V_62 , V_57 -> V_63 ,
V_57 -> V_64 , V_10 ) ) != NULL ) {
if ( ( V_10 -> V_65 & V_57 -> V_66 ) != V_57 -> V_65 )
continue;
F_44 ( V_10 ) ;
F_30 ( V_10 , V_57 , V_46 ) ;
}
}
return 0 ;
}
int F_45 ( struct V_1 * V_2 , T_3 * V_67 )
{
struct V_42 * V_68 ;
T_3 V_69 , V_70 ;
* V_67 = 0 ;
if ( ! V_2 -> V_10 )
return - V_28 ;
V_68 = V_2 -> V_10 -> V_15 -> V_71 ;
if ( V_68 -> V_61 == V_72 ||
V_68 -> V_61 == V_73 )
return - V_28 ;
F_46 ( V_68 , V_74 , & V_69 ) ;
F_46 ( V_68 , V_75 , & V_70 ) ;
if ( V_70 ) {
if ( V_70 & V_76 )
* V_67 |= V_77 ;
if ( V_70 & V_78 )
* V_67 |= V_79 ;
if ( V_70 & V_80 )
* V_67 |= V_81 ;
} else {
if ( V_69 & V_82 )
* V_67 |= V_77 ;
if ( V_69 & V_83 )
* V_67 |= ( V_77 | V_79 ) ;
}
F_47 ( L_4 , V_68 -> V_61 , V_68 -> V_62 , V_69 , V_70 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 , T_3 * V_84 )
{
struct V_42 * V_68 ;
T_3 V_69 ;
* V_84 = 0 ;
if ( ! V_2 -> V_10 )
return - V_28 ;
V_68 = V_2 -> V_10 -> V_15 -> V_71 ;
F_46 ( V_68 , V_74 , & V_69 ) ;
* V_84 = ( V_69 & V_85 ) >> 4 ;
F_47 ( L_5 , V_68 -> V_61 , V_68 -> V_62 , V_69 ) ;
return 0 ;
}
int F_40 ( struct V_45 * V_46 , struct V_55 * V_56 )
{
return - 1 ;
}
void F_27 ( struct V_1 * V_2 ) {}
int F_20 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
return - V_28 ;
}
void F_49 ( struct V_45 * V_46 , struct V_55 * V_56 )
{
struct V_1 * V_2 , * V_86 ;
F_19 ( L_3 ) ;
if ( ! ( V_46 -> V_59 & V_33 ) ) {
F_50 ( V_56 ) ;
} else {
F_51 (dev, tmp, &driver->legacy_dev_list,
legacy_dev_list) {
F_52 ( & V_2 -> V_54 ) ;
F_53 ( V_2 ) ;
}
}
F_47 ( L_6 ) ;
}
