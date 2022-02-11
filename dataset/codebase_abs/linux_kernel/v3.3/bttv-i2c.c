static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
if ( V_2 )
V_4 -> V_5 |= 0x02 ;
else
V_4 -> V_5 &= ~ 0x02 ;
F_2 ( V_4 -> V_5 , V_6 ) ;
F_3 ( V_6 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
if ( V_2 )
V_4 -> V_5 |= 0x01 ;
else
V_4 -> V_5 &= ~ 0x01 ;
F_2 ( V_4 -> V_5 , V_6 ) ;
F_3 ( V_6 ) ;
}
static int F_5 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
int V_2 ;
V_2 = F_3 ( V_6 ) & 0x02 ? 1 : 0 ;
return V_2 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
int V_2 ;
V_2 = F_3 ( V_6 ) & 0x01 ;
return V_2 ;
}
static T_1 F_7 ( struct V_7 * V_8 )
{
return V_9 ;
}
static int
F_8 ( struct V_3 * V_4 )
{
int V_10 = 0 ;
if ( F_9 ( V_4 -> V_11 ,
V_4 -> V_12 , F_10 ( 85 ) ) == - V_13 )
V_10 = - V_14 ;
if ( V_4 -> V_12 & V_15 )
V_10 = 1 ;
V_4 -> V_12 = 0 ;
return V_10 ;
}
static int
F_11 ( struct V_3 * V_4 , const struct V_16 * V_17 , int V_18 )
{
T_1 V_19 ;
int V_20 , V_21 ;
if ( 0 == V_17 -> V_22 )
return - V_23 ;
V_19 = ( V_17 -> V_24 << 25 ) | ( V_17 -> V_25 [ 0 ] << 16 ) | V_26 ;
if ( V_17 -> V_22 > 1 || ! V_18 )
V_19 |= V_27 ;
F_2 ( V_19 , V_6 ) ;
V_20 = F_8 ( V_4 ) ;
if ( V_20 < 0 )
goto V_28;
if ( V_20 == 0 )
goto V_29;
if ( V_30 ) {
F_12 ( L_1 , V_17 -> V_24 << 1 , V_17 -> V_25 [ 0 ] ) ;
}
for ( V_21 = 1 ; V_21 < V_17 -> V_22 ; V_21 ++ ) {
V_19 = ( V_17 -> V_25 [ V_21 ] << 24 ) | V_26 | V_31 ;
if ( V_21 < V_17 -> V_22 - 1 || ! V_18 )
V_19 |= V_27 ;
F_2 ( V_19 , V_6 ) ;
V_20 = F_8 ( V_4 ) ;
if ( V_20 < 0 )
goto V_28;
if ( V_20 == 0 )
goto V_29;
if ( V_30 )
F_12 ( L_2 , V_17 -> V_25 [ V_21 ] ) ;
}
if ( ! ( V_19 & V_27 ) )
F_12 ( L_3 ) ;
return V_17 -> V_22 ;
V_29:
V_20 = - V_14 ;
V_28:
if ( V_30 )
F_12 ( L_4 , V_20 ) ;
return V_20 ;
}
static int
F_13 ( struct V_3 * V_4 , const struct V_16 * V_17 , int V_18 )
{
T_1 V_19 ;
T_1 V_21 ;
int V_20 ;
for ( V_21 = 0 ; V_21 < V_17 -> V_22 ; V_21 ++ ) {
V_19 = ( V_17 -> V_24 << 25 ) | ( 1 << 24 ) | V_26 ;
if ( V_21 < V_17 -> V_22 - 1 )
V_19 |= V_32 ;
if ( V_21 < V_17 -> V_22 - 1 || ! V_18 )
V_19 |= V_27 ;
if ( V_21 )
V_19 |= V_31 ;
if ( V_30 ) {
if ( ! ( V_19 & V_31 ) )
F_12 ( L_5 , ( V_17 -> V_24 << 1 ) + 1 ) ;
}
F_2 ( V_19 , V_6 ) ;
V_20 = F_8 ( V_4 ) ;
if ( V_20 < 0 )
goto V_28;
if ( V_20 == 0 )
goto V_29;
V_17 -> V_25 [ V_21 ] = ( ( T_1 ) F_3 ( V_6 ) >> 8 ) & 0xff ;
if ( V_30 ) {
F_12 ( L_6 , V_17 -> V_25 [ V_21 ] ) ;
}
if ( V_30 && ! ( V_19 & V_27 ) )
F_12 ( L_7 ) ;
}
return V_17 -> V_22 ;
V_29:
V_20 = - V_14 ;
V_28:
if ( V_30 )
F_12 ( L_4 , V_20 ) ;
return V_20 ;
}
static int F_14 ( struct V_7 * V_33 , struct V_16 * V_34 , int V_35 )
{
struct V_36 * V_37 = F_15 ( V_33 ) ;
struct V_3 * V_4 = F_16 ( V_37 ) ;
int V_20 = 0 ;
int V_38 ;
if ( V_30 )
F_17 ( L_8 ) ;
F_2 ( V_39 | V_15 , V_40 ) ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
if ( V_34 [ V_38 ] . V_41 & V_42 ) {
V_20 = F_13 ( V_4 , & V_34 [ V_38 ] , V_38 + 1 == V_35 ) ;
if ( V_20 < 0 )
goto V_28;
} else {
V_20 = F_11 ( V_4 , & V_34 [ V_38 ] , V_38 + 1 == V_35 ) ;
if ( V_20 < 0 )
goto V_28;
}
}
return V_35 ;
V_28:
return V_20 ;
}
int F_18 ( struct V_3 * V_4 , unsigned char V_24 , char * V_43 )
{
unsigned char V_44 = 0 ;
if ( 0 != V_4 -> V_45 )
return - 1 ;
if ( V_46 && NULL != V_43 )
F_19 ( L_9 ,
V_4 -> V_47 . V_48 , V_43 , V_24 ) ;
V_4 -> V_49 . V_24 = V_24 >> 1 ;
if ( 1 != F_20 ( & V_4 -> V_49 , & V_44 , 1 ) ) {
if ( NULL != V_43 ) {
if ( V_46 )
F_12 ( L_10 ) ;
} else
F_21 ( L_11 ,
V_4 -> V_47 . V_48 , V_24 ) ;
return - 1 ;
}
if ( V_46 && NULL != V_43 )
F_12 ( L_12 ) ;
return V_44 ;
}
int F_22 ( struct V_3 * V_4 , unsigned char V_24 , unsigned char V_50 ,
unsigned char V_51 , int V_52 )
{
unsigned char V_44 [ 2 ] ;
int V_53 = V_52 ? 2 : 1 ;
if ( 0 != V_4 -> V_45 )
return - 1 ;
V_4 -> V_49 . V_24 = V_24 >> 1 ;
V_44 [ 0 ] = V_50 ;
V_44 [ 1 ] = V_51 ;
if ( V_53 != F_23 ( & V_4 -> V_49 , V_44 , V_53 ) )
return - 1 ;
return 0 ;
}
void T_2 F_24 ( struct V_3 * V_4 , unsigned char * V_54 , int V_24 )
{
memset ( V_54 , 0 , 256 ) ;
if ( 0 != V_4 -> V_45 )
return;
V_4 -> V_49 . V_24 = V_24 >> 1 ;
F_25 ( & V_4 -> V_49 , V_54 , 256 ) ;
}
static void F_26 ( char * V_55 , struct V_49 * V_47 )
{
unsigned char V_25 ;
int V_38 , V_10 ;
for ( V_38 = 0 ; V_38 < F_27 ( V_56 ) ; V_38 ++ ) {
V_47 -> V_24 = V_38 ;
V_10 = F_20 ( V_47 , & V_25 , 0 ) ;
if ( V_10 < 0 )
continue;
F_19 ( L_13 ,
V_55 , V_38 << 1 , V_56 [ V_38 ] ? V_56 [ V_38 ] : L_14 ) ;
}
}
int T_2 F_28 ( struct V_3 * V_4 )
{
F_29 ( V_4 -> V_49 . V_55 , L_15 , V_57 ) ;
if ( V_58 )
V_4 -> V_59 = 1 ;
if ( V_4 -> V_59 ) {
F_29 ( V_4 -> V_47 . V_33 . V_55 , L_16 ,
sizeof( V_4 -> V_47 . V_33 . V_55 ) ) ;
V_4 -> V_47 . V_33 . V_60 = & V_61 ;
} else {
if ( V_62 < 5 )
V_62 = 5 ;
F_29 ( V_4 -> V_47 . V_33 . V_55 , L_17 ,
sizeof( V_4 -> V_47 . V_33 . V_55 ) ) ;
memcpy ( & V_4 -> V_63 , & V_64 ,
sizeof( V_64 ) ) ;
V_4 -> V_63 . V_65 = V_62 ;
V_4 -> V_63 . V_1 = V_4 ;
V_4 -> V_47 . V_33 . V_66 = & V_4 -> V_63 ;
}
V_4 -> V_47 . V_33 . V_67 = V_68 ;
V_4 -> V_47 . V_33 . V_69 . V_70 = & V_4 -> V_47 . V_71 -> V_69 ;
snprintf ( V_4 -> V_47 . V_33 . V_55 , sizeof( V_4 -> V_47 . V_33 . V_55 ) ,
L_18 , V_4 -> V_72 , V_4 -> V_47 . V_48 ,
V_4 -> V_59 ? L_19 : L_20 ) ;
F_30 ( & V_4 -> V_47 . V_33 , & V_4 -> V_47 . V_37 ) ;
V_4 -> V_49 . V_73 = & V_4 -> V_47 . V_33 ;
if ( V_4 -> V_59 ) {
V_4 -> V_45 = F_31 ( & V_4 -> V_47 . V_33 ) ;
} else {
F_1 ( V_4 , 1 ) ;
F_4 ( V_4 , 1 ) ;
V_4 -> V_45 = F_32 ( & V_4 -> V_47 . V_33 ) ;
}
if ( 0 == V_4 -> V_45 && V_74 )
F_26 ( V_4 -> V_47 . V_37 . V_55 , & V_4 -> V_49 ) ;
return V_4 -> V_45 ;
}
