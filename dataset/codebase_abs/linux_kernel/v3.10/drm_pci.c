T_1 * F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 * V_5 ;
#if 1
unsigned long V_6 ;
T_2 V_7 ;
#endif
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
F_5 ( F_6 ( V_6 ) ) ;
}
return V_5 ;
}
void F_7 ( struct V_1 * V_2 , T_1 * V_5 )
{
#if 1
unsigned long V_6 ;
T_2 V_7 ;
#endif
if ( V_5 -> V_9 ) {
for ( V_6 = ( unsigned long ) V_5 -> V_9 , V_7 = V_5 -> V_3 ;
V_7 > 0 ; V_6 += V_13 , V_7 -= V_13 ) {
F_8 ( F_6 ( V_6 ) ) ;
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
static int F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_10 -> V_16 ;
}
static const char * F_15 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 -> V_20 . V_21 ;
return V_18 -> V_22 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_25 , V_26 ;
struct V_17 * V_18 = V_2 -> V_19 -> V_20 . V_21 ;
V_24 -> V_27 = 40 ;
V_24 -> V_28 = V_24 -> V_27 ;
V_24 -> V_29 = F_2 ( V_24 -> V_28 , V_8 ) ;
if ( V_24 -> V_29 == NULL )
return - V_30 ;
V_25 = snprintf ( V_24 -> V_29 , V_24 -> V_27 ,
L_1 ,
F_11 ( V_2 ) ,
V_2 -> V_10 -> V_15 -> V_31 ,
F_17 ( V_2 -> V_10 -> V_32 ) ,
F_18 ( V_2 -> V_10 -> V_32 ) ) ;
if ( V_25 >= V_24 -> V_27 ) {
F_19 ( L_2 ) ;
V_26 = - V_33 ;
goto V_34;
} else
V_24 -> V_27 = V_25 ;
V_2 -> V_35 =
F_2 ( strlen ( V_18 -> V_22 ) +
V_24 -> V_27 + 2 , V_8 ) ;
if ( V_2 -> V_35 == NULL ) {
V_26 = - V_30 ;
goto V_34;
}
sprintf ( V_2 -> V_35 , L_3 , V_18 -> V_22 ,
V_24 -> V_29 ) ;
return 0 ;
V_34:
return V_26 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_36 * V_37 )
{
int V_38 , V_15 , V_39 , V_40 , V_26 ;
const char * V_41 ;
V_24 -> V_27 = V_37 -> V_27 ;
V_24 -> V_28 = V_37 -> V_27 + 1 ;
V_24 -> V_29 = F_2 ( V_24 -> V_28 , V_8 ) ;
if ( ! V_24 -> V_29 ) {
V_26 = - V_30 ;
goto V_34;
}
if ( F_21 ( V_24 -> V_29 , V_37 -> V_29 , V_24 -> V_27 ) ) {
V_26 = - V_42 ;
goto V_34;
}
V_24 -> V_29 [ V_24 -> V_27 ] = '\0' ;
V_41 = V_2 -> V_19 -> V_15 -> V_43 ( V_2 ) ;
V_2 -> V_35 = F_2 ( strlen ( V_41 ) +
strlen ( V_24 -> V_29 ) + 2 , V_8 ) ;
if ( ! V_2 -> V_35 ) {
V_26 = - V_30 ;
goto V_34;
}
sprintf ( V_2 -> V_35 , L_3 , V_41 ,
V_24 -> V_29 ) ;
V_26 = sscanf ( V_24 -> V_29 , L_4 , & V_15 , & V_39 , & V_40 ) ;
if ( V_26 != 3 ) {
V_26 = - V_33 ;
goto V_34;
}
V_38 = V_15 >> 8 ;
V_15 &= 0xff ;
if ( ( V_38 != F_11 ( V_2 ) ) ||
( V_15 != V_2 -> V_10 -> V_15 -> V_31 ) ||
( V_39 != F_17 ( V_2 -> V_10 -> V_32 ) ) ||
( V_40 != F_18 ( V_2 -> V_10 -> V_32 ) ) ) {
V_26 = - V_33 ;
goto V_34;
}
return 0 ;
V_34:
return V_26 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
if ( ( V_45 -> V_46 >> 8 ) != F_11 ( V_2 ) ||
( V_45 -> V_46 & 0xff ) != V_2 -> V_10 -> V_15 -> V_31 ||
V_45 -> V_47 != F_17 ( V_2 -> V_10 -> V_32 ) || V_45 -> V_48 != F_18 ( V_2 -> V_10 -> V_32 ) )
return - V_33 ;
V_45 -> V_16 = V_2 -> V_10 -> V_16 ;
F_23 ( L_5 , V_45 -> V_46 , V_45 -> V_47 , V_45 -> V_48 ,
V_45 -> V_16 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) ) {
if ( F_26 ( V_2 ) )
V_2 -> V_49 = F_27 ( V_2 ) ;
if ( F_28 ( V_2 , V_50 )
&& ( V_2 -> V_49 == NULL ) ) {
F_19 ( L_6 ) ;
return - V_33 ;
}
if ( F_29 ( V_2 ) ) {
if ( V_2 -> V_49 )
V_2 -> V_49 -> V_51 =
F_30 ( V_2 -> V_49 -> V_52 . V_53 ,
V_2 -> V_49 -> V_52 . V_54 *
1024 * 1024 , V_55 , 1 ) ;
}
}
return 0 ;
}
int F_31 ( struct V_56 * V_10 , const struct V_57 * V_58 ,
struct V_59 * V_19 )
{
struct V_1 * V_2 ;
int V_26 ;
F_23 ( L_7 ) ;
V_2 = F_32 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return - V_30 ;
V_26 = F_33 ( V_10 ) ;
if ( V_26 )
goto V_60;
V_2 -> V_10 = V_10 ;
V_2 -> V_2 = & V_10 -> V_2 ;
V_2 -> V_61 = V_10 -> V_62 ;
V_2 -> V_63 = V_10 -> V_64 ;
#ifdef F_12
V_2 -> V_65 = V_10 -> V_66 ;
#endif
F_34 ( & V_67 ) ;
if ( ( V_26 = F_35 ( V_2 , V_58 , V_19 ) ) ) {
F_36 ( V_68 L_8 ) ;
goto V_69;
}
if ( F_28 ( V_2 , V_70 ) ) {
F_37 ( V_10 , V_2 ) ;
V_26 = F_38 ( V_2 , & V_2 -> V_71 , V_72 ) ;
if ( V_26 )
goto V_69;
}
if ( ( V_26 = F_38 ( V_2 , & V_2 -> V_73 , V_74 ) ) )
goto V_75;
if ( V_2 -> V_19 -> V_76 ) {
V_26 = V_2 -> V_19 -> V_76 ( V_2 , V_58 -> V_77 ) ;
if ( V_26 )
goto V_78;
}
if ( F_28 ( V_2 , V_70 ) ) {
V_26 = F_39 ( V_2 ,
& V_2 -> V_73 -> V_79 ) ;
if ( V_26 )
goto V_78;
}
F_40 ( & V_2 -> V_80 , & V_19 -> V_81 ) ;
F_41 ( L_9 ,
V_19 -> V_22 , V_19 -> V_82 , V_19 -> V_83 , V_19 -> V_84 ,
V_19 -> V_85 , F_42 ( V_10 ) , V_2 -> V_73 -> V_86 ) ;
F_43 ( & V_67 ) ;
return 0 ;
V_78:
F_44 ( & V_2 -> V_73 ) ;
V_75:
if ( F_28 ( V_2 , V_70 ) )
F_44 ( & V_2 -> V_71 ) ;
V_69:
F_45 ( V_10 ) ;
V_60:
F_4 ( V_2 ) ;
F_43 ( & V_67 ) ;
return V_26 ;
}
int F_46 ( struct V_59 * V_19 , struct V_17 * V_18 )
{
struct V_56 * V_10 = NULL ;
const struct V_57 * V_87 ;
int V_88 ;
F_23 ( L_7 ) ;
F_47 ( & V_19 -> V_81 ) ;
V_19 -> V_20 . V_21 = V_18 ;
V_19 -> V_15 = & V_89 ;
if ( V_19 -> V_90 & V_70 )
return F_48 ( V_18 ) ;
for ( V_88 = 0 ; V_18 -> V_91 [ V_88 ] . V_64 != 0 ; V_88 ++ ) {
V_87 = & V_18 -> V_91 [ V_88 ] ;
V_10 = NULL ;
while ( ( V_10 =
F_49 ( V_87 -> V_64 , V_87 -> V_62 , V_87 -> V_92 ,
V_87 -> V_93 , V_10 ) ) != NULL ) {
if ( ( V_10 -> V_94 & V_87 -> V_95 ) != V_87 -> V_94 )
continue;
F_50 ( V_10 ) ;
F_31 ( V_10 , V_87 , V_19 ) ;
}
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 , T_3 * V_96 )
{
struct V_56 * V_97 ;
T_3 V_98 , V_99 ;
* V_96 = 0 ;
if ( ! V_2 -> V_10 )
return - V_33 ;
V_97 = V_2 -> V_10 -> V_15 -> V_100 ;
if ( V_97 -> V_64 == V_101 ||
V_97 -> V_64 == V_102 )
return - V_33 ;
F_52 ( V_97 , V_103 , & V_98 ) ;
F_52 ( V_97 , V_104 , & V_99 ) ;
if ( V_99 ) {
if ( V_99 & V_105 )
* V_96 |= V_106 ;
if ( V_99 & V_107 )
* V_96 |= V_108 ;
if ( V_99 & V_109 )
* V_96 |= V_110 ;
} else {
if ( V_98 & V_111 )
* V_96 |= V_106 ;
if ( V_98 & V_112 )
* V_96 |= ( V_106 | V_108 ) ;
}
F_41 ( L_10 , V_97 -> V_64 , V_97 -> V_62 , V_98 , V_99 ) ;
return 0 ;
}
int F_46 ( struct V_59 * V_19 , struct V_17 * V_18 )
{
return - 1 ;
}
void F_53 ( struct V_59 * V_19 , struct V_17 * V_18 )
{
struct V_1 * V_2 , * V_113 ;
F_23 ( L_7 ) ;
if ( V_19 -> V_90 & V_70 ) {
F_54 ( V_18 ) ;
} else {
F_55 (dev, tmp, &driver->device_list, driver_item)
F_56 ( V_2 ) ;
}
F_41 ( L_11 ) ;
}
