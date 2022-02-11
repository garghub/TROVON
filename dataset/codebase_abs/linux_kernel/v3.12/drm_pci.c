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
F_5 ( F_6 ( V_6 ) ) ;
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
if ( V_2 -> V_49 ) {
V_2 -> V_49 -> V_51 = F_29 (
V_2 -> V_49 -> V_52 . V_53 ,
V_2 -> V_49 -> V_52 . V_54 *
1024 * 1024 ) ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) && V_2 -> V_49 ) {
F_31 ( V_2 -> V_49 -> V_51 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
}
}
int F_34 ( struct V_55 * V_10 , const struct V_56 * V_57 ,
struct V_58 * V_19 )
{
struct V_1 * V_2 ;
int V_26 ;
F_23 ( L_7 ) ;
V_2 = F_35 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return - V_30 ;
V_26 = F_36 ( V_10 ) ;
if ( V_26 )
goto V_59;
V_2 -> V_10 = V_10 ;
V_2 -> V_2 = & V_10 -> V_2 ;
V_2 -> V_60 = V_10 -> V_61 ;
V_2 -> V_62 = V_10 -> V_63 ;
#ifdef F_12
V_2 -> V_64 = V_10 -> V_65 ;
#endif
F_37 ( & V_66 ) ;
if ( ( V_26 = F_38 ( V_2 , V_57 , V_19 ) ) ) {
F_39 ( V_67 L_8 ) ;
goto V_68;
}
if ( F_28 ( V_2 , V_69 ) ) {
F_40 ( V_10 , V_2 ) ;
V_26 = F_41 ( V_2 , & V_2 -> V_70 , V_71 ) ;
if ( V_26 )
goto V_68;
}
if ( F_28 ( V_2 , V_72 ) && V_73 ) {
V_26 = F_41 ( V_2 , & V_2 -> V_74 , V_75 ) ;
if ( V_26 )
goto V_76;
}
if ( ( V_26 = F_41 ( V_2 , & V_2 -> V_77 , V_78 ) ) )
goto V_79;
if ( V_2 -> V_19 -> V_80 ) {
V_26 = V_2 -> V_19 -> V_80 ( V_2 , V_57 -> V_81 ) ;
if ( V_26 )
goto V_82;
}
if ( F_28 ( V_2 , V_69 ) ) {
V_26 = F_42 ( V_2 ,
& V_2 -> V_77 -> V_83 ) ;
if ( V_26 )
goto V_82;
}
F_43 ( & V_2 -> V_84 , & V_19 -> V_85 ) ;
F_44 ( L_9 ,
V_19 -> V_22 , V_19 -> V_86 , V_19 -> V_87 , V_19 -> V_88 ,
V_19 -> V_89 , F_45 ( V_10 ) , V_2 -> V_77 -> V_90 ) ;
F_46 ( & V_66 ) ;
return 0 ;
V_82:
F_47 ( & V_2 -> V_77 ) ;
V_79:
if ( V_2 -> V_74 )
F_47 ( & V_2 -> V_74 ) ;
V_76:
if ( F_28 ( V_2 , V_69 ) )
F_47 ( & V_2 -> V_70 ) ;
V_68:
F_48 ( V_10 ) ;
V_59:
F_4 ( V_2 ) ;
F_46 ( & V_66 ) ;
return V_26 ;
}
int F_49 ( struct V_58 * V_19 , struct V_17 * V_18 )
{
struct V_55 * V_10 = NULL ;
const struct V_56 * V_91 ;
int V_92 ;
F_23 ( L_7 ) ;
F_50 ( & V_19 -> V_85 ) ;
V_19 -> V_20 . V_21 = V_18 ;
V_19 -> V_15 = & V_93 ;
if ( V_19 -> V_94 & V_69 )
return F_51 ( V_18 ) ;
for ( V_92 = 0 ; V_18 -> V_95 [ V_92 ] . V_63 != 0 ; V_92 ++ ) {
V_91 = & V_18 -> V_95 [ V_92 ] ;
V_10 = NULL ;
while ( ( V_10 =
F_52 ( V_91 -> V_63 , V_91 -> V_61 , V_91 -> V_96 ,
V_91 -> V_97 , V_10 ) ) != NULL ) {
if ( ( V_10 -> V_98 & V_91 -> V_99 ) != V_91 -> V_98 )
continue;
F_53 ( V_10 ) ;
F_34 ( V_10 , V_91 , V_19 ) ;
}
}
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_3 * V_100 )
{
struct V_55 * V_101 ;
T_3 V_102 , V_103 ;
* V_100 = 0 ;
if ( ! V_2 -> V_10 )
return - V_33 ;
V_101 = V_2 -> V_10 -> V_15 -> V_104 ;
if ( V_101 -> V_63 == V_105 ||
V_101 -> V_63 == V_106 )
return - V_33 ;
F_55 ( V_101 , V_107 , & V_102 ) ;
F_55 ( V_101 , V_108 , & V_103 ) ;
if ( V_103 ) {
if ( V_103 & V_109 )
* V_100 |= V_110 ;
if ( V_103 & V_111 )
* V_100 |= V_112 ;
if ( V_103 & V_113 )
* V_100 |= V_114 ;
} else {
if ( V_102 & V_115 )
* V_100 |= V_110 ;
if ( V_102 & V_116 )
* V_100 |= ( V_110 | V_112 ) ;
}
F_44 ( L_10 , V_101 -> V_63 , V_101 -> V_61 , V_102 , V_103 ) ;
return 0 ;
}
int F_49 ( struct V_58 * V_19 , struct V_17 * V_18 )
{
return - 1 ;
}
void F_56 ( struct V_58 * V_19 , struct V_17 * V_18 )
{
struct V_1 * V_2 , * V_117 ;
F_23 ( L_7 ) ;
if ( V_19 -> V_94 & V_69 ) {
F_57 ( V_18 ) ;
} else {
F_58 (dev, tmp, &driver->device_list, driver_item)
F_59 ( V_2 ) ;
}
F_44 ( L_11 ) ;
}
