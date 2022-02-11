static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 , int V_7 )
{
struct V_8 * V_9 =
(struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
V_9 -> Type = V_12 | 0x00 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = F_2 ( V_7 ) ;
memset ( V_9 -> V_15 , 0 , sizeof ( V_9 -> V_15 ) ) ;
F_3 ( V_4 , L_1 , V_7 ) ;
V_11 = F_4 ( V_4 , V_6 , V_9 ,
V_16 , NULL ) ;
if ( V_11 != V_17 ) {
F_3 ( V_4 , L_2 ) ;
return V_18 ;
}
F_3 ( V_4 , L_3 ) ;
V_11 = F_5 ( V_4 , V_5 , V_2 ) ;
F_3 ( V_4 , L_4 ) ;
if ( V_11 > V_19 )
return V_18 ;
return V_20 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int unsigned V_5 , unsigned int V_6 , int V_7 )
{
struct V_8 * V_9 =
(struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
V_9 -> Type = V_21 | 0x00 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = F_2 ( V_7 ) ;
memset ( V_9 -> V_15 , 0 , sizeof ( V_9 -> V_15 ) ) ;
F_3 ( V_4 , L_5 , V_7 ) ;
V_11 = F_4 ( V_4 , V_6 , V_9 ,
V_16 , NULL ) ;
if ( V_11 != V_17 ) {
F_3 ( V_4 , L_6 ) ;
return V_18 ;
}
F_3 ( V_4 , L_7 ) ;
V_11 = F_5 ( V_4 , V_6 , V_2 ) ;
F_3 ( V_4 , L_8 ) ;
if ( V_11 > V_19 )
return V_18 ;
return V_20 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_5 , V_6 ;
int V_11 ;
unsigned int V_26 ;
int V_27 ;
V_23 = (struct V_22 * ) V_4 -> V_10 ;
V_25 = (struct V_24 * ) V_4 -> V_10 ;
F_3 ( V_4 , L_9 ) ;
V_6 = V_4 -> V_28 ;
V_5 = V_4 -> V_29 ;
V_23 -> Type = V_30 | 0x00 ;
V_23 -> V_13 = 0 ;
memcpy ( V_23 -> V_31 , V_2 -> V_32 , 12 ) ;
memset ( V_23 -> V_33 , 0 , sizeof ( V_23 -> V_33 ) ) ;
F_8 ( F_9 ( V_4 , V_2 -> V_32 , 12 ) ) ;
V_11 = F_4 ( V_4 , V_6 , V_23 ,
V_16 , NULL ) ;
if ( V_11 != V_17 ) {
F_3 ( V_4 , L_10 ) ;
return V_18 ;
}
V_11 = F_4 ( V_4 , V_5 , V_25 ,
V_34 , & V_26 ) ;
F_3 ( V_4 , L_11 , V_11 , V_26 ) ;
if ( V_11 != V_17 )
return V_18 ;
F_8 ( F_9 ( V_4 , ( void * ) V_25 , V_26 ) ) ;
while ( V_25 -> V_35 & V_36 ) {
F_3 ( V_4 , L_12 ) ;
F_3 ( V_4 , L_13 , V_25 -> V_35 ) ;
V_23 -> Type = V_37 ;
V_23 -> V_13 = 0 ;
memset ( V_23 -> V_31 , 0 , sizeof( V_23 -> V_31 ) ) ;
memset ( V_23 -> V_33 , 0 , sizeof ( V_23 -> V_33 ) ) ;
V_11 = F_4 ( V_4 , V_6 , V_23 ,
V_16 , NULL ) ;
if ( V_11 != V_17 ) {
F_3 ( V_4 , L_10 ) ;
return V_18 ;
}
V_11 = F_4 ( V_4 , V_5 , V_25 ,
V_34 , & V_26 ) ;
F_3 ( V_4 , L_14 , V_11 , V_26 ) ;
if ( V_11 != V_17 )
return V_18 ;
F_8 ( F_9 ( V_4 , ( void * ) V_25 , V_26 ) ) ;
}
if ( V_26 != 4 )
return V_18 ;
if ( ( V_25 -> V_35 & 1 ) != 0 ) {
F_3 ( V_4 , L_15 ) ;
return V_38 ;
}
F_3 ( V_4 , L_16 ,
F_10 ( V_25 -> V_14 ) ) ;
F_3 ( V_4 , L_17 , F_11 ( V_2 ) ) ;
switch ( V_2 -> V_32 [ 0 ] ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
V_27 = F_10 ( V_25 -> V_14 ) ;
break;
default:
V_27 = F_11 ( V_2 ) ;
}
if ( V_27 > F_11 ( V_2 ) ) {
V_27 = F_11 ( V_2 ) ;
F_3 ( V_4 , L_18 ,
V_27 ) ;
}
switch ( V_4 -> V_2 -> V_43 ) {
case V_44 :
if ( ! V_27 )
break;
if ( ( V_25 -> V_35 & V_45 ) == 0 || ( V_25 -> V_46 & 3 ) != 2 ) {
F_3 ( V_4 , L_19 ) ;
return V_38 ;
}
V_11 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_27 ) ;
if ( V_11 != V_20 )
return V_11 ;
F_3 ( V_4 , L_20 ) ;
V_11 = F_4 ( V_4 , V_5 , V_25 ,
V_16 , & V_26 ) ;
F_8 ( F_9 ( V_4 , ( void * ) V_25 , V_26 ) ) ;
if ( V_26 != 4 || V_11 > V_19 )
return V_18 ;
if ( ( V_25 -> V_35 & V_47 ) != 0 ) {
F_3 ( V_4 , L_15 ) ;
return V_38 ;
}
if ( ( V_25 -> V_46 & 3 ) != 3 ) {
F_3 ( V_4 , L_21 ) ;
return V_38 ;
}
F_3 ( V_4 , L_22 ) ;
break;
case V_48 :
if ( ! V_27 )
break;
V_11 = F_6 ( V_2 , V_4 , V_5 , V_6 , V_27 ) ;
if ( V_11 != V_20 )
return V_11 ;
F_3 ( V_4 , L_20 ) ;
V_11 = F_4 ( V_4 , V_5 , V_25 ,
V_16 , & V_26 ) ;
if ( V_26 != 4 || V_11 > V_19 )
return V_18 ;
if ( ( V_25 -> V_35 & V_47 ) != 0 ) {
F_3 ( V_4 , L_15 ) ;
return V_38 ;
}
if ( ( V_25 -> V_46 & 3 ) != 3 ) {
F_3 ( V_4 , L_21 ) ;
return V_38 ;
}
F_3 ( V_4 , L_22 ) ;
break;
case V_49 :
break;
default:
F_3 ( V_4 , L_23 ,
V_4 -> V_2 -> V_43 ) ;
return V_38 ;
break;
}
return V_20 ;
}
static int F_12 ( struct V_3 * V_4 )
{
int V_11 ;
char * V_50 = V_4 -> V_10 ;
V_11 = F_13 ( V_4 , V_4 -> V_51 ,
0x4c , 0xc0 , 0x4346 , 0x0 , V_50 , 0x20 , 3 * V_52 ) ;
V_50 [ 32 ] = '\0' ;
F_3 ( V_4 , L_24 , V_50 ) ;
V_11 = F_13 ( V_4 , V_4 -> V_53 ,
0x4d , 0x40 , 0x24d8 , 0x0 , NULL , 0x0 , 3 * V_52 ) ;
F_3 ( V_4 , L_25 , V_11 ) ;
F_14 ( 250 ) ;
V_11 = F_13 ( V_4 , V_4 -> V_53 ,
0x4d , 0x40 , 0x24f8 , 0x0 , NULL , 0x0 , 3 * V_52 ) ;
F_3 ( V_4 , L_26 , V_11 ) ;
F_14 ( 3 * 1000 ) ;
return V_20 ;
}
static int F_15 ( struct V_3 * V_4 )
{
F_16 ( V_54 L_27 ) ;
return V_55 ;
}
static void F_9 ( struct V_3 * V_4 , void * V_56 , int V_27 )
{
static char line [ 80 ] ;
int V_57 = 0 ;
unsigned char * V_50 = ( unsigned char * ) V_56 ;
int V_58 , V_59 ;
int V_60 , V_61 ;
V_57 = 0 ;
for ( V_58 = 0 ; V_58 < V_27 ; V_58 ++ ) {
if ( ( V_58 & 15 ) == 0 ) {
if ( V_58 > 0 ) {
V_57 += sprintf ( line + V_57 , L_28 ) ;
for ( V_59 = V_58 - 16 ; V_59 < V_58 ; V_59 ++ ) {
if ( V_50 [ V_59 ] >= 32 && V_50 [ V_59 ] <= 126 )
line [ V_57 ++ ] = V_50 [ V_59 ] ;
else
line [ V_57 ++ ] = '.' ;
}
line [ V_57 ] = 0 ;
F_3 ( V_4 , L_29 , line ) ;
V_57 = 0 ;
}
V_57 += sprintf ( line + V_57 , L_30 , V_58 ) ;
} else if ( ( V_58 & 7 ) == 0 ) {
V_57 += sprintf ( line + V_57 , L_31 ) ;
}
V_57 += sprintf ( line + V_57 , L_32 , V_50 [ V_58 ] & 0xff ) ;
}
V_60 = ( V_27 - 1 ) % 16 ;
V_61 = ( ( V_27 - 1 ) / 16 ) * 16 ;
for ( V_58 = V_60 + 1 ; V_58 < 16 ; V_58 ++ )
V_57 += sprintf ( line + V_57 , L_33 ) ;
if ( V_60 < 8 )
V_57 += sprintf ( line + V_57 , L_34 ) ;
V_57 += sprintf ( line + V_57 , L_28 ) ;
for ( V_58 = 0 ; V_58 <= V_60 ; V_58 ++ ) {
if ( V_50 [ V_61 + V_58 ] >= 32 && V_50 [ V_61 + V_58 ] <= 126 )
line [ V_57 ++ ] = V_50 [ V_61 + V_58 ] ;
else
line [ V_57 ++ ] = '.' ;
}
line [ V_57 ] = 0 ;
F_3 ( V_4 , L_29 , line ) ;
V_57 = 0 ;
}
static int F_17 ( struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
struct V_3 * V_4 ;
int V_11 ;
V_11 = F_18 ( & V_4 , V_63 , V_65 ,
( V_65 - V_66 ) + V_67 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_68 = L_35 ;
V_4 -> V_69 = F_7 ;
V_4 -> V_70 = F_15 ;
V_4 -> V_71 = 0 ;
V_11 = F_19 ( V_4 ) ;
return V_11 ;
}
