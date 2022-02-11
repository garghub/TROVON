static int F_1 ( void )
{
return - V_1 ;
}
static int F_2 ( void )
{
return - V_1 ;
}
static void F_3 ( T_1 * V_2 , int V_3 , int V_4 )
{
V_2 [ 0 ] = ( V_3 >> 16 ) & 0xff ;
V_2 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_2 [ 2 ] = V_3 & 0xff ;
V_2 [ 3 ] = V_4 ;
}
static void F_4 ( T_1 * V_5 , int V_4 )
{
F_5 ( V_6 , V_7 , 1 , L_1 ) ;
F_5 ( V_6 , V_7 , 1 , L_2 , V_4 ) ;
V_5 [ V_4 ] = F_6 ( V_5 , V_4 ) ;
F_5 ( V_6 , V_7 , 1 , L_3 , V_5 [ V_4 ] ) ;
}
static int F_7 ( struct V_8 * V_9 , T_1 * V_2 , T_1 * V_10 , T_1 V_11 , int V_12 )
{
T_1 V_13 ;
F_8 ( & V_9 -> V_14 ) ;
F_9 ( V_9 ) ;
F_10 ( 65 ) ;
if ( F_11 ( V_9 , V_2 , V_11 ) ) {
F_5 ( V_6 , V_15 , 1 , L_4 ) ;
F_12 ( V_9 ) ;
goto error;
}
if ( ( F_13 ( V_9 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_5 ) ;
goto error;
}
if ( F_14 ( V_9 , & V_13 , V_17 ) < 0 ) {
F_5 ( V_6 , V_15 , 1 , L_6 ) ;
F_12 ( V_9 ) ;
goto error;
}
if ( V_12 ) {
if ( ! F_15 ( V_9 , V_18 ) ) {
F_5 ( V_6 , V_19 , 1 , L_7 ) ;
goto error;
}
if ( F_14 ( V_9 , V_10 , 128 ) < 0 ) {
F_5 ( V_6 , V_15 , 1 , L_6 ) ;
F_12 ( V_9 ) ;
goto error;
}
}
F_16 ( & V_9 -> V_14 ) ;
return 0 ;
error:
F_16 ( & V_9 -> V_14 ) ;
return - V_20 ;
}
static int F_17 ( struct V_8 * V_9 , T_1 * V_2 , int V_11 , T_1 * V_10 , int V_12 )
{
T_1 V_21 = 0 ;
while ( V_21 < V_22 ) {
F_5 ( V_6 , V_19 , 1 , L_8 ) ;
if ( F_7 ( V_9 , V_2 , V_10 , V_11 , V_12 ) ) {
F_12 ( V_9 ) ;
V_21 ++ ;
} else {
break;
}
}
if( V_21 == V_22 )
return - 1 ;
return 0 ;
}
static int F_18 ( struct V_8 * V_9 )
{
int V_4 , V_23 ;
static T_1 V_3 [ 8 ] = { 0x07 , 0x40 , 0x01 , 0x00 , 0x01 , 0x00 , 0x00 , 0xff } ;
F_4 ( & V_3 [ 0 ] , V_3 [ 0 ] ) ;
if ( ( F_17 ( V_9 , V_3 , sizeof( V_3 ) , V_9 -> V_24 , V_25 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_9 ) ;
return - 1 ;
}
F_5 ( V_6 , V_15 , 1 , L_10 ) ;
F_5 ( V_6 , V_15 , 1 , L_11 ) ;
F_5 ( V_6 , V_15 , 1 , L_12 ,
V_9 -> V_24 [ 7 ] , ( V_9 -> V_24 [ 8 ] << 8 ) | V_9 -> V_24 [ 9 ] ,
( V_9 -> V_24 [ 10 ] << 8 ) | V_9 -> V_24 [ 11 ] , V_26 , ( char * ) ( & V_9 -> V_24 [ 12 ] ) ) ;
F_5 ( V_6 , V_15 , 1 , L_13 ) ;
V_4 = V_9 -> V_24 [ 5 ] ;
V_23 = V_4 - 6 ;
if ( V_23 < 0 ) {
V_23 = 0 ;
F_5 ( V_6 , V_16 , 1 , L_14 ) ;
}
F_3 ( & V_9 -> V_24 [ 0 ] , V_27 , V_4 ) ;
memcpy ( & V_9 -> V_24 [ 4 ] , & V_9 -> V_24 [ 7 ] , 5 ) ;
V_9 -> V_24 [ 9 ] = V_23 ;
memcpy ( & V_9 -> V_24 [ 10 ] , & V_9 -> V_24 [ 12 ] , V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 )
{
int V_28 , V_29 , V_30 , V_31 ;
static T_1 V_32 [ 8 ] = { 0x07 , 0x40 , 0x00 , 0x00 , 0x02 , 0x00 , 0x00 , 0xff } ;
const int V_33 = 8 , V_34 = 4 , V_35 = 7 ;
F_4 ( & V_32 [ 0 ] , V_32 [ 0 ] ) ;
if ( ( F_17 ( V_9 , V_32 , sizeof ( V_32 ) , V_9 -> V_24 , V_25 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_9 ) ;
return - 1 ;
}
F_5 ( V_6 , V_15 , 1 , L_10 ) ;
F_5 ( V_6 , V_15 , 0 , L_15 ) ;
for ( V_30 = 0 ; V_30 < V_9 -> V_24 [ 0 ] + 1 ; V_30 ++ ) {
F_5 ( V_6 , V_15 , 0 , L_16 , V_9 -> V_24 [ V_30 ] ) ;
}
F_5 ( V_6 , V_15 , 0 , L_17 ) ;
V_31 = V_9 -> V_24 [ V_35 ] ;
if ( V_31 >= 100 ) {
V_31 = 100 ;
F_5 ( V_6 , V_16 , 1 , L_18 ) ;
}
F_3 ( & V_9 -> V_24 [ 0 ] , V_36 , V_31 * 2 ) ;
F_5 ( V_6 , V_15 , 0 , L_19 ) ;
V_28 = V_33 ;
V_29 = V_34 ;
for( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
F_5 ( V_6 , V_15 , 0 , L_20 , V_9 -> V_24 [ V_28 + 0 ] , V_9 -> V_24 [ V_28 + 1 ] ) ;
V_9 -> V_24 [ V_29 + 0 ] = V_9 -> V_24 [ V_28 + 0 ] ;
V_9 -> V_24 [ V_29 + 1 ] = V_9 -> V_24 [ V_28 + 1 ] ;
V_28 += 2 ;
V_29 += 2 ;
}
F_5 ( V_6 , V_15 , 0 , L_17 ) ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 , struct V_37 * V_38 , void T_2 * V_39 )
{
int V_30 ;
T_1 V_40 [ 256 ] ;
static T_1 V_32 [ 8 ] = { 0x07 , 0x40 , 0x02 , 0x00 , 0x02 , 0x00 , 0x00 , 0xff } ;
F_4 ( & V_32 [ 0 ] , V_32 [ 0 ] ) ;
if ( ( F_17 ( V_9 , V_32 , sizeof ( V_32 ) , V_40 , V_25 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_9 ) ;
return - 1 ;
}
F_5 ( V_6 , V_19 , 1 , L_10 ) ;
F_5 ( V_6 , V_15 , 1 , L_21 , V_40 [ 7 ] ) ;
F_5 ( V_6 , V_15 , 0 , L_22 ) ;
for ( V_30 = 0 ; V_30 < V_40 [ 0 ] + 1 ; V_30 ++ )
F_5 ( V_6 , V_15 , 0 , L_23 , V_40 [ V_30 ] ) ;
F_5 ( V_6 , V_15 , 0 , L_24 ) ;
V_38 -> V_41 = 1 ;
V_38 -> V_42 = 1 ;
V_38 -> V_43 = V_40 [ 7 ] ;
V_38 -> V_44 = 1 ;
if ( F_21 ( V_39 , V_38 , sizeof ( struct V_37 ) ) )
return - V_45 ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 , struct V_46 * V_47 , void T_2 * V_39 )
{
return - V_1 ;
}
static int F_23 ( struct V_8 * V_9 , struct V_48 * V_49 , void T_2 * V_39 )
{
int V_30 ;
static T_1 V_32 [ 8 ] = { 0x00 , 0x05 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xff } ;
T_1 * V_50 = V_9 -> V_24 ;
F_4 ( & V_32 [ 0 ] , 7 ) ;
if ( ( F_17 ( V_9 , V_32 , sizeof ( V_32 ) , V_50 , V_25 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_9 ) ;
return - 1 ;
}
F_5 ( V_6 , V_15 , 1 , L_10 ) ;
F_5 ( V_6 , V_15 , 1 , L_25 , V_50 [ 3 ] ) ;
F_5 ( V_6 , V_15 , 0 , L_22 ) ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ )
F_5 ( V_6 , V_15 , 0 , L_23 , V_50 [ V_30 ] ) ;
F_5 ( V_6 , V_15 , 0 , L_24 ) ;
if ( V_50 [ 4 ] & 0x80 ) {
V_49 -> V_51 = V_52 ;
V_49 -> V_53 = 1 ;
V_49 -> type = V_54 ;
} else if ( V_50 [ 4 ] & 0x40 ) {
V_49 -> V_51 = V_55 ;
V_49 -> V_53 = 1 ;
V_49 -> type = V_54 ;
} else
V_49 -> V_51 = 0 ;
if ( F_21 ( V_39 , V_49 , sizeof ( struct V_48 ) ) )
return - V_45 ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 , struct V_46 * V_47 , void T_2 * V_39 )
{
T_1 V_30 = 0 ;
T_3 V_3 = 0 ;
if ( F_25 ( V_47 , V_39 , sizeof ( struct V_46 ) ) )
return - V_45 ;
if ( V_47 -> V_56 ) {
F_5 ( V_6 , V_19 , 1 , L_26 ,
3 , V_47 -> V_56 ) ;
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ ) {
V_3 = V_3 | V_47 -> V_56 [ V_30 ] ;
if ( V_30 < 2 )
V_3 = V_3 << 8 ;
}
F_5 ( V_6 , V_19 , 1 , L_27 , V_3 ) ;
switch ( V_3 ) {
case V_27 :
memcpy ( V_47 -> V_56 , V_9 -> V_24 , 128 ) ;
if ( F_21 ( V_39 , V_47 , sizeof ( struct V_46 ) ) )
return - V_45 ;
break;
case V_36 :
memcpy ( V_47 -> V_56 , V_9 -> V_24 , 128 ) ;
if ( F_21 ( V_39 , V_47 , sizeof ( struct V_46 ) ) )
return - V_45 ;
break;
}
}
return 0 ;
}
static int F_26 ( struct V_8 * V_9 , struct V_46 * V_47 , struct V_46 * V_57 , T_3 V_4 )
{
if ( V_9 -> V_58 & V_59 ) {
V_57 -> V_56 [ 2 ] = V_47 -> V_56 [ 1 ] ;
V_57 -> V_56 [ 3 ] = V_47 -> V_56 [ 2 ] ;
} else {
if ( V_4 > 247 ) {
F_5 ( V_6 , V_16 , 1 , L_28 ) ;
return - 1 ;
}
V_57 -> V_56 [ 0 ] = ( V_4 & 0xff ) + 7 ;
V_57 -> V_56 [ 1 ] = 0x40 ;
V_57 -> V_56 [ 2 ] = 0x03 ;
V_57 -> V_56 [ 3 ] = 0x00 ;
V_57 -> V_56 [ 4 ] = 0x03 ;
V_57 -> V_56 [ 5 ] = V_4 & 0xff ;
V_57 -> V_56 [ 6 ] = 0x00 ;
memcpy ( & V_57 -> V_56 [ 7 ] , & V_47 -> V_56 [ 4 ] , V_4 ) ;
}
return 0 ;
}
static int F_27 ( struct V_8 * V_9 , struct V_46 * V_57 , T_1 V_4 , T_1 V_13 )
{
if ( ( F_17 ( V_9 , V_57 -> V_56 , V_4 , V_57 -> V_56 , V_13 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_29 ) ;
F_5 ( V_6 , V_19 , 1 , L_30 ) ;
F_28 ( V_9 ) ;
return - 1 ;
}
F_5 ( V_6 , V_19 , 1 , L_31 ) ;
return 0 ;
}
static T_3 F_29 ( T_1 * V_60 )
{
T_1 V_61 = 0 , V_62 = 0 , V_63 = 0 ;
T_3 V_4 = 0 ;
V_61 = V_60 [ 0 ] ;
F_5 ( V_6 , V_7 , 1 , L_32 , V_61 ) ;
if ( V_61 < 0x80 ) {
V_4 = V_61 & 0x7f ;
F_5 ( V_6 , V_7 , 1 , L_33 , V_4 ) ;
} else {
V_62 = V_61 & 0x7f ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
V_4 = V_4 << 8 ;
V_4 += V_60 [ V_63 + 1 ] ;
F_5 ( V_6 , V_7 , 1 , L_34 , V_4 ) ;
}
}
return V_4 ;
}
static int F_30 ( T_1 * V_56 , T_3 V_4 , T_3 V_64 )
{
T_3 V_30 ;
F_5 ( V_6 , V_7 , 0 , L_35 ) ;
for ( V_30 = V_64 ; V_30 < V_4 ; V_30 ++ )
F_5 ( V_6 , V_7 , 0 , L_36 , V_56 [ V_30 ] ) ;
F_5 ( V_6 , V_7 , 0 , L_17 ) ;
return 0 ;
}
static int F_31 ( struct V_8 * V_9 , struct V_46 * V_47 , struct V_46 * V_57 , T_1 V_13 , T_1 V_65 )
{
T_3 V_4 = 0 ;
T_1 V_66 = 8 ;
V_4 = F_29 ( & V_47 -> V_56 [ 3 ] ) ;
F_5 ( V_6 , V_7 , 1 , L_37 , V_4 ) ;
F_30 ( & V_47 -> V_56 [ 4 ] , V_4 , 0 ) ;
memset ( V_57 -> V_56 , '\0' , V_4 ) ;
F_26 ( V_9 , V_47 , V_57 , V_4 ) ;
F_4 ( V_57 -> V_56 , V_57 -> V_56 [ 0 ] ) ;
F_30 ( V_57 -> V_56 , ( V_4 + V_66 ) , 0 ) ;
F_27 ( V_9 , V_57 , ( V_4 + V_66 ) , V_13 ) ;
return 0 ;
}
static int F_32 ( struct V_8 * V_9 , struct V_46 * V_47 , struct V_46 * V_57 )
{
int V_67 = 0 ;
if ( V_67 ) {
if ( ( F_31 ( V_9 , V_47 , V_57 , 1 , V_25 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_38 ) ;
return - 1 ;
}
F_5 ( V_6 , V_16 , 1 , L_39 ) ;
}
if ( ! V_67 ) {
if ( ( F_31 ( V_9 , V_47 , V_57 , 0 , V_68 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_38 ) ;
return - 1 ;
}
F_5 ( V_6 , V_19 , 1 , L_40 ) ;
}
return 0 ;
}
static int F_33 ( struct V_8 * V_9 , struct V_46 * V_47 , void T_2 * V_39 )
{
int V_30 = 0 ;
T_3 V_3 = 0 ;
struct V_46 * V_57 ;
int V_69 = 0 ;
if ( ( V_57 = F_34 ( sizeof ( struct V_46 ) , V_70 ) ) == NULL ) {
F_5 ( V_6 , V_16 , 1 , L_41 ) ;
return - V_71 ;
}
F_5 ( V_6 , V_7 , 1 , L_42 ) ;
if ( F_25 ( V_47 , V_39 , sizeof ( struct V_46 ) ) ) {
V_69 = - V_45 ;
goto V_72;
}
if ( V_47 -> V_56 ) {
V_3 = 0 ;
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ ) {
V_3 = V_3 | V_47 -> V_56 [ V_30 ] ;
if ( V_30 < 2 )
V_3 = V_3 << 8 ;
}
F_5 ( V_6 , V_7 , 1 , L_43 , V_3 ) ;
switch ( V_3 ) {
case V_73 :
F_5 ( V_6 , V_7 , 1 , L_44 ) ;
if ( ( F_31 ( V_9 , V_47 , V_57 , 0 , 0 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_45 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_46 ) ;
break;
case V_74 :
F_5 ( V_6 , V_15 , 1 , L_47 ) ;
if ( ( F_32 ( V_9 , V_47 , V_57 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_48 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_49 ) ;
break;
case V_75 :
F_5 ( V_6 , V_15 , 1 , L_50 ) ;
if ( ( F_18 ( V_9 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_51 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_52 ) ;
break;
case V_76 :
F_5 ( V_6 , V_15 , 1 , L_53 ) ;
if ( ( F_19 ( V_9 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_54 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_55 ) ;
break;
}
}
V_72:
F_35 ( V_57 ) ;
return V_69 ;
}
static long F_36 ( struct V_77 * V_77 , unsigned int V_78 , unsigned long V_79 )
{
struct V_80 * V_81 ;
struct V_8 * V_9 ;
struct V_48 * V_49 ;
struct V_37 * V_38 ;
struct V_46 * V_47 ;
void T_2 * V_39 = ( void T_2 * ) V_79 ;
int V_69 = 0 ;
F_8 ( & V_82 ) ;
V_81 = V_77 -> V_83 ;
V_9 = (struct V_8 * ) V_81 -> V_84 ;
V_47 = F_34 ( sizeof ( struct V_46 ) , V_70 ) ;
V_49 = F_34 ( sizeof ( struct V_48 ) , V_70 ) ;
V_38 = F_34 ( sizeof ( struct V_37 ) , V_70 ) ;
if ( ! V_47 || ! V_49 || ! V_38 ) {
F_5 ( V_6 , V_16 , 1 , L_41 ) ;
V_69 = - V_71 ;
goto V_72;
}
switch ( V_78 ) {
case V_85 :
F_5 ( V_6 , V_15 , 1 , L_56 ) ;
if ( ( F_33 ( V_9 , V_47 , V_39 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_57 ) ;
V_69 = - 1 ;
goto V_72;
}
break;
case V_86 :
F_5 ( V_6 , V_15 , 1 , L_58 ) ;
if ( ( F_24 ( V_9 , V_47 , V_39 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_59 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_60 ) ;
break;
case V_87 :
F_5 ( V_6 , V_16 , 1 , L_61 ) ;
F_37 ( V_9 ) ;
F_10 ( 4000 ) ;
break;
case V_88 :
F_5 ( V_6 , V_15 , 1 , L_62 ) ;
if ( ( F_23 ( V_9 , V_49 , V_39 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_63 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_64 ) ;
break;
case V_89 :
F_5 ( V_6 , V_15 , 1 , L_65 ) ;
if ( ( F_20 ( V_9 , V_38 , V_39 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_66 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_67 ) ;
break;
case V_90 :
F_5 ( V_6 , V_15 , 1 , L_68 ) ;
if ( ( F_22 ( V_9 , V_47 , V_39 ) ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_69 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_70 ) ;
break;
case V_91 :
F_5 ( V_6 , V_15 , 1 , L_71 ) ;
if ( ( F_1 () ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_72 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_73 ) ;
break;
case V_92 :
F_5 ( V_6 , V_15 , 1 , L_74 ) ;
if ( ( F_2 () ) < 0 ) {
F_5 ( V_6 , V_16 , 1 , L_75 ) ;
V_69 = - 1 ;
goto V_72;
}
F_5 ( V_6 , V_15 , 1 , L_76 ) ;
default:
V_69 = - V_1 ;
}
V_72:
F_35 ( V_47 ) ;
F_35 ( V_49 ) ;
F_35 ( V_38 ) ;
F_16 ( & V_82 ) ;
return V_69 ;
}
static int F_38 ( struct V_93 * V_93 , struct V_77 * V_77 )
{
F_5 ( V_6 , V_7 , 1 , L_77 , V_77 ) ;
F_39 ( V_94 ) ;
return 0 ;
}
static int F_40 ( struct V_93 * V_93 , struct V_77 * V_77 )
{
F_5 ( V_6 , V_7 , 1 , L_78 ) ;
F_41 ( V_94 ) ;
return 0 ;
}
static T_4 F_42 ( struct V_77 * V_77 , char T_2 * V_95 , T_5 V_4 , T_6 * V_64 )
{
T_4 V_96 = 0 ;
F_5 ( V_6 , V_7 , 1 , L_79 ) ;
return V_96 ;
}
static T_4 F_43 ( struct V_77 * V_77 , const char T_2 * V_95 , T_5 V_4 , T_6 * V_64 )
{
F_5 ( V_6 , V_7 , 1 , L_80 ) ;
return 0 ;
}
struct V_80 * F_44 ( struct V_8 * V_97 , struct V_98 * V_98 )
{
struct V_80 * V_81 ;
F_5 ( V_6 , V_16 , 1 , L_81 ) ;
if ( F_45 ( V_98 , & V_81 , & V_99 , V_97 , V_100 ) == 0 ) {
V_97 -> V_101 = V_81 ;
return V_97 -> V_101 ;
}
return NULL ;
}
