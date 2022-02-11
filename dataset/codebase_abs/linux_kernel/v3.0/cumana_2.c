static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_7 , V_5 -> V_8 + V_9 ) ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_10 , V_5 -> V_8 + V_9 ) ;
}
static void
F_4 ( struct V_11 * V_12 , int V_13 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
if ( V_13 ) {
V_5 -> V_15 = 1 ;
F_2 ( V_16 , V_5 -> V_8 + V_9 ) ;
} else {
V_5 -> V_15 = 0 ;
F_2 ( V_17 , V_5 -> V_8 + V_9 ) ;
}
}
static T_1
F_5 ( int V_18 , void * V_19 )
{
struct V_4 * V_5 = V_19 ;
return F_6 ( & V_5 -> V_5 ) ;
}
static T_2
F_7 ( struct V_11 * V_12 , struct V_20 * V_21 ,
T_3 V_22 , T_2 V_23 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
struct V_24 * V_25 = F_8 ( V_12 ) ;
int V_26 = V_5 -> V_5 . V_27 . V_28 ;
F_2 ( V_29 , V_5 -> V_8 + V_9 ) ;
if ( V_26 != V_30 &&
( V_23 == V_31 || V_21 -> V_32 >= 512 ) ) {
int V_33 , V_34 , V_35 , V_36 ;
V_33 = F_9 ( & V_5 -> V_37 [ 0 ] , V_21 , V_38 ) ;
if ( V_22 == V_39 )
V_34 = V_40 ,
V_35 = V_41 ,
V_36 = V_42 ;
else
V_34 = V_43 ,
V_35 = V_44 ,
V_36 = V_45 ;
F_10 ( V_25 , V_5 -> V_37 , V_33 , V_34 ) ;
F_11 ( V_26 ) ;
F_12 ( V_26 , V_5 -> V_37 , V_33 ) ;
F_2 ( V_36 , V_5 -> V_8 + V_9 ) ;
F_13 ( V_26 , V_35 ) ;
F_14 ( V_26 ) ;
F_2 ( V_46 , V_5 -> V_8 + V_9 ) ;
F_2 ( V_47 , V_5 -> V_8 + V_9 ) ;
return V_31 ;
}
return V_48 ;
}
static void
F_15 ( struct V_11 * V_12 , struct V_20 * V_21 ,
T_3 V_22 , int V_49 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
unsigned int V_50 ;
unsigned char * V_51 ;
V_50 = V_21 -> V_32 ;
V_51 = V_21 -> V_52 ;
if ( V_22 == V_39 )
#if 0
while (length > 1) {
unsigned long word;
unsigned int status = readb(info->base + CUMANASCSI2_STATUS);
if (status & STATUS_INT)
goto end;
if (!(status & STATUS_DRQ))
continue;
word = *addr | *(addr + 1) << 8;
writew(word, info->base + CUMANASCSI2_PSEUDODMA);
addr += 2;
length -= 2;
}
#else
F_16 ( L_1 ) ;
#endif
else {
if ( V_49 && ( V_49 & 255 ) ) {
while ( V_50 >= 256 ) {
unsigned int V_53 = F_17 ( V_5 -> V_8 + V_54 ) ;
if ( V_53 & V_55 )
return;
if ( ! ( V_53 & V_56 ) )
continue;
F_18 ( V_5 -> V_8 + V_57 ,
V_51 , 256 >> 1 ) ;
V_51 += 256 ;
V_50 -= 256 ;
}
}
while ( V_50 > 0 ) {
unsigned long V_58 ;
unsigned int V_53 = F_17 ( V_5 -> V_8 + V_54 ) ;
if ( V_53 & V_55 )
return;
if ( ! ( V_53 & V_56 ) )
continue;
V_58 = F_19 ( V_5 -> V_8 + V_57 ) ;
* V_51 ++ = V_58 ;
if ( -- V_50 > 0 ) {
* V_51 ++ = V_58 >> 8 ;
V_50 -- ;
}
}
}
}
static void
F_20 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
if ( V_5 -> V_5 . V_27 . V_28 != V_30 ) {
F_2 ( V_29 , V_5 -> V_8 + V_9 ) ;
F_11 ( V_5 -> V_5 . V_27 . V_28 ) ;
}
}
const char * F_21 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
static char string [ 150 ] ;
sprintf ( string , L_2 ,
V_12 -> V_59 -> V_60 , V_5 -> V_5 . V_27 . type , V_5 -> V_2 -> V_61 ,
V_62 , V_5 -> V_15 ? L_3 : L_4 ) ;
return string ;
}
static int
F_22 ( struct V_11 * V_12 , char * V_63 , int V_50 )
{
int V_64 = V_50 ;
if ( V_50 >= 11 && strncmp ( V_63 , L_5 , 11 ) == 0 ) {
V_63 += 11 ;
V_50 -= 11 ;
if ( V_50 >= 5 && strncmp ( V_63 , L_6 , 5 ) == 0 ) {
if ( V_63 [ 5 ] == '1' )
F_4 ( V_12 , 1 ) ;
else if ( V_63 [ 5 ] == '0' )
F_4 ( V_12 , 0 ) ;
else
V_64 = - V_65 ;
} else
V_64 = - V_65 ;
} else
V_64 = - V_65 ;
return V_64 ;
}
int F_23 ( struct V_11 * V_12 , char * V_63 , char * * V_66 , T_4 V_67 ,
int V_50 , int V_68 )
{
struct V_4 * V_5 ;
char * V_69 = V_63 ;
int V_70 ;
if ( V_68 == 1 )
return F_22 ( V_12 , V_63 , V_50 ) ;
V_5 = (struct V_4 * ) V_12 -> V_14 ;
V_69 += sprintf ( V_69 , L_7 , V_62 ) ;
V_69 += F_24 ( & V_5 -> V_5 , V_69 ) ;
V_69 += sprintf ( V_69 , L_8 ,
V_5 -> V_15 ? L_3 : L_4 ) ;
V_69 += F_25 ( & V_5 -> V_5 , V_69 ) ;
V_69 += F_26 ( & V_5 -> V_5 , V_69 ) ;
* V_66 = V_63 + V_67 ;
V_70 = V_69 - V_63 - V_67 ;
if ( V_70 > V_50 )
V_70 = V_50 ;
return V_70 ;
}
static int T_5
F_27 ( struct V_1 * V_2 , const struct V_71 * V_72 )
{
struct V_11 * V_12 ;
struct V_4 * V_5 ;
void T_6 * V_8 ;
int V_64 ;
V_64 = F_28 ( V_2 ) ;
if ( V_64 )
goto V_73;
V_8 = F_29 ( V_2 , V_74 , 0 , 0 ) ;
if ( ! V_8 ) {
V_64 = - V_75 ;
goto V_76;
}
V_12 = F_30 ( & V_77 ,
sizeof( struct V_4 ) ) ;
if ( ! V_12 ) {
V_64 = - V_75 ;
goto V_76;
}
F_31 ( V_2 , V_12 ) ;
V_5 = (struct V_4 * ) V_12 -> V_14 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_8 = V_8 ;
F_4 ( V_12 , V_78 [ V_2 -> V_61 ] ) ;
V_5 -> V_5 . V_27 . V_79 = V_8 + V_80 ;
V_5 -> V_5 . V_27 . V_81 = V_82 ;
V_5 -> V_5 . V_27 . V_18 = V_2 -> V_18 ;
V_5 -> V_5 . V_27 . V_28 = V_2 -> V_28 ;
V_5 -> V_5 . V_83 . V_84 = 40 ;
V_5 -> V_5 . V_83 . V_85 = 255 ;
V_5 -> V_5 . V_83 . V_86 = 200 ;
V_5 -> V_5 . V_83 . V_87 = 7 ;
V_5 -> V_5 . V_83 . V_88 = V_89 | V_90 | V_91 ;
V_5 -> V_5 . V_83 . V_92 = 1 ;
V_5 -> V_5 . V_83 . V_93 = 0 ;
V_5 -> V_5 . V_83 . V_94 = V_95 ;
V_5 -> V_5 . V_28 . V_96 = F_7 ;
V_5 -> V_5 . V_28 . V_97 = F_15 ;
V_5 -> V_5 . V_28 . V_98 = F_20 ;
V_2 -> V_99 = V_5 -> V_8 + V_54 ;
V_2 -> V_100 = V_55 ;
F_32 ( V_2 , & V_101 , V_5 ) ;
V_64 = F_33 ( V_12 ) ;
if ( V_64 )
goto V_102;
V_64 = F_34 ( V_2 -> V_18 , F_5 ,
V_103 , L_9 , V_5 ) ;
if ( V_64 ) {
F_16 ( L_10 ,
V_12 -> V_104 , V_2 -> V_18 , V_64 ) ;
goto V_105;
}
if ( V_5 -> V_5 . V_27 . V_28 != V_30 ) {
if ( F_35 ( V_5 -> V_5 . V_27 . V_28 , L_9 ) ) {
F_16 ( L_11 ,
V_12 -> V_104 , V_5 -> V_5 . V_27 . V_28 ) ;
V_5 -> V_5 . V_27 . V_28 = V_30 ;
} else {
F_36 ( V_5 -> V_5 . V_27 . V_28 , 180 ) ;
V_5 -> V_5 . V_83 . V_94 |= V_106 ;
}
}
V_64 = F_37 ( V_12 , & V_2 -> V_25 ) ;
if ( V_64 == 0 )
goto V_73;
if ( V_5 -> V_5 . V_27 . V_28 != V_30 )
F_38 ( V_5 -> V_5 . V_27 . V_28 ) ;
F_39 ( V_2 -> V_18 , V_12 ) ;
V_105:
F_40 ( V_12 ) ;
V_102:
F_41 ( V_12 ) ;
V_76:
F_42 ( V_2 ) ;
V_73:
return V_64 ;
}
static void T_7 F_43 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_44 ( V_2 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
F_31 ( V_2 , NULL ) ;
F_45 ( V_12 ) ;
if ( V_5 -> V_5 . V_27 . V_28 != V_30 )
F_38 ( V_5 -> V_5 . V_27 . V_28 ) ;
F_39 ( V_2 -> V_18 , V_5 ) ;
F_40 ( V_12 ) ;
F_41 ( V_12 ) ;
F_42 ( V_2 ) ;
}
static int T_8 F_46 ( void )
{
return F_47 ( & V_107 ) ;
}
static void T_9 F_48 ( void )
{
F_49 ( & V_107 ) ;
}
