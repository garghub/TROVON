static void F_1 ( T_1 * V_1 , int V_2 , int V_3 )
{
V_1 [ 0 ] = ( V_2 >> 16 ) & 0xff ;
V_1 [ 1 ] = ( V_2 >> 8 ) & 0xff ;
V_1 [ 2 ] = V_2 & 0xff ;
V_1 [ 3 ] = V_3 ;
}
static void F_2 ( T_1 * V_4 , int V_3 )
{
F_3 ( V_5 , V_6 , 1 , L_1 ) ;
F_3 ( V_5 , V_6 , 1 , L_2 , V_3 ) ;
V_4 [ V_3 ] = F_4 ( V_4 , V_3 ) ;
F_3 ( V_5 , V_6 , 1 , L_3 , V_4 [ V_3 ] ) ;
}
static int F_5 ( struct V_7 * V_8 , T_1 * V_1 , T_1 * V_9 , T_1 V_10 , int V_11 )
{
T_1 V_12 ;
F_6 ( & V_8 -> V_13 ) ;
F_7 ( V_8 ) ;
F_8 ( 65 ) ;
if ( F_9 ( V_8 , V_1 , V_10 ) ) {
F_3 ( V_5 , V_14 , 1 , L_4 ) ;
F_10 ( V_8 ) ;
goto error;
}
if ( ( F_11 ( V_8 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_5 ) ;
goto error;
}
if ( F_12 ( V_8 , & V_12 , V_16 ) < 0 ) {
F_3 ( V_5 , V_14 , 1 , L_6 ) ;
F_10 ( V_8 ) ;
goto error;
}
if ( V_11 ) {
if ( ! F_13 ( V_8 , V_17 ) ) {
F_3 ( V_5 , V_18 , 1 , L_7 ) ;
goto error;
}
if ( F_12 ( V_8 , V_9 , 128 ) < 0 ) {
F_3 ( V_5 , V_14 , 1 , L_6 ) ;
F_10 ( V_8 ) ;
goto error;
}
}
F_14 ( & V_8 -> V_13 ) ;
return 0 ;
error:
F_14 ( & V_8 -> V_13 ) ;
return - V_19 ;
}
static int F_15 ( struct V_7 * V_8 , T_1 * V_1 , int V_10 , T_1 * V_9 , int V_11 )
{
T_1 V_20 = 0 ;
while ( V_20 < V_21 ) {
F_3 ( V_5 , V_18 , 1 , L_8 ) ;
if ( F_5 ( V_8 , V_1 , V_9 , V_10 , V_11 ) ) {
F_10 ( V_8 ) ;
V_20 ++ ;
} else {
break;
}
}
if( V_20 == V_21 )
return - V_19 ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 )
{
int V_3 , V_22 ;
static T_1 V_2 [ 8 ] = { 0x07 , 0x40 , 0x01 , 0x00 , 0x01 , 0x00 , 0x00 , 0xff } ;
F_2 ( & V_2 [ 0 ] , V_2 [ 0 ] ) ;
if ( ( F_15 ( V_8 , V_2 , sizeof( V_2 ) , V_8 -> V_23 , V_24 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_9 ) ;
return - V_19 ;
}
F_3 ( V_5 , V_14 , 1 , L_10 ) ;
F_3 ( V_5 , V_14 , 1 , L_11 ) ;
F_3 ( V_5 , V_14 , 1 , L_12 ,
V_8 -> V_23 [ 7 ] , ( V_8 -> V_23 [ 8 ] << 8 ) | V_8 -> V_23 [ 9 ] ,
( V_8 -> V_23 [ 10 ] << 8 ) | V_8 -> V_23 [ 11 ] , V_25 , ( char * ) ( & V_8 -> V_23 [ 12 ] ) ) ;
F_3 ( V_5 , V_14 , 1 , L_13 ) ;
V_3 = V_8 -> V_23 [ 5 ] ;
V_22 = V_3 - 6 ;
if ( V_22 < 0 ) {
V_22 = 0 ;
F_3 ( V_5 , V_15 , 1 , L_14 ) ;
}
F_1 ( & V_8 -> V_23 [ 0 ] , V_26 , V_3 ) ;
memmove ( & V_8 -> V_23 [ 4 ] , & V_8 -> V_23 [ 7 ] , 5 ) ;
V_8 -> V_23 [ 9 ] = V_22 ;
memmove ( & V_8 -> V_23 [ 10 ] , & V_8 -> V_23 [ 12 ] , V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 )
{
int V_27 , V_28 , V_29 , V_30 ;
static T_1 V_31 [ 8 ] = { 0x07 , 0x40 , 0x00 , 0x00 , 0x02 , 0x00 , 0x00 , 0xff } ;
const int V_32 = 8 , V_33 = 4 , V_34 = 7 ;
F_2 ( & V_31 [ 0 ] , V_31 [ 0 ] ) ;
if ( ( F_15 ( V_8 , V_31 , sizeof ( V_31 ) , V_8 -> V_23 , V_24 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_9 ) ;
return - V_19 ;
}
F_3 ( V_5 , V_14 , 1 , L_10 ) ;
F_3 ( V_5 , V_14 , 0 , L_15 ) ;
for ( V_29 = 0 ; V_29 < V_8 -> V_23 [ 0 ] + 1 ; V_29 ++ ) {
F_3 ( V_5 , V_14 , 0 , L_16 , V_8 -> V_23 [ V_29 ] ) ;
}
F_3 ( V_5 , V_14 , 0 , L_17 ) ;
V_30 = V_8 -> V_23 [ V_34 ] ;
if ( V_30 >= 100 ) {
V_30 = 100 ;
F_3 ( V_5 , V_15 , 1 , L_18 ) ;
}
F_1 ( & V_8 -> V_23 [ 0 ] , V_35 , V_30 * 2 ) ;
F_3 ( V_5 , V_14 , 0 , L_19 ) ;
V_27 = V_32 ;
V_28 = V_33 ;
for( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
F_3 ( V_5 , V_14 , 0 , L_20 , V_8 -> V_23 [ V_27 + 0 ] , V_8 -> V_23 [ V_27 + 1 ] ) ;
V_8 -> V_23 [ V_28 + 0 ] = V_8 -> V_23 [ V_27 + 0 ] ;
V_8 -> V_23 [ V_28 + 1 ] = V_8 -> V_23 [ V_27 + 1 ] ;
V_27 += 2 ;
V_28 += 2 ;
}
F_3 ( V_5 , V_14 , 0 , L_17 ) ;
return 0 ;
}
static int F_18 ( struct V_7 * V_8 , struct V_36 * V_37 , void T_2 * V_38 )
{
int V_29 ;
T_1 V_39 [ 256 ] ;
static T_1 V_31 [ 8 ] = { 0x07 , 0x40 , 0x02 , 0x00 , 0x02 , 0x00 , 0x00 , 0xff } ;
F_2 ( & V_31 [ 0 ] , V_31 [ 0 ] ) ;
if ( ( F_15 ( V_8 , V_31 , sizeof ( V_31 ) , V_39 , V_24 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_9 ) ;
return - V_19 ;
}
F_3 ( V_5 , V_18 , 1 , L_10 ) ;
F_3 ( V_5 , V_14 , 1 , L_21 , V_39 [ 7 ] ) ;
F_3 ( V_5 , V_14 , 0 , L_22 ) ;
for ( V_29 = 0 ; V_29 < V_39 [ 0 ] + 1 ; V_29 ++ )
F_3 ( V_5 , V_14 , 0 , L_23 , V_39 [ V_29 ] ) ;
F_3 ( V_5 , V_14 , 0 , L_24 ) ;
V_37 -> V_40 = 1 ;
V_37 -> V_41 = 1 ;
V_37 -> V_42 = V_39 [ 7 ] ;
V_37 -> V_43 = 1 ;
if ( F_19 ( V_38 , V_37 , sizeof ( struct V_36 ) ) )
return - V_44 ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_45 * V_46 , void T_2 * V_38 )
{
return - V_47 ;
}
static int F_21 ( struct V_7 * V_8 , struct V_48 * V_49 , void T_2 * V_38 )
{
int V_29 ;
static T_1 V_31 [ 8 ] = { 0x00 , 0x05 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xff } ;
T_1 * V_50 = V_8 -> V_23 ;
F_2 ( & V_31 [ 0 ] , 7 ) ;
if ( ( F_15 ( V_8 , V_31 , sizeof ( V_31 ) , V_50 , V_24 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_9 ) ;
return - V_19 ;
}
F_3 ( V_5 , V_14 , 1 , L_10 ) ;
F_3 ( V_5 , V_14 , 1 , L_25 , V_50 [ 3 ] ) ;
F_3 ( V_5 , V_14 , 0 , L_22 ) ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
F_3 ( V_5 , V_14 , 0 , L_23 , V_50 [ V_29 ] ) ;
F_3 ( V_5 , V_14 , 0 , L_24 ) ;
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
if ( F_19 ( V_38 , V_49 , sizeof ( struct V_48 ) ) )
return - V_44 ;
return 0 ;
}
static int F_22 ( struct V_7 * V_8 , struct V_45 * V_46 , void T_2 * V_38 )
{
T_1 V_29 = 0 ;
T_3 V_2 = 0 ;
if ( F_23 ( V_46 , V_38 , sizeof ( struct V_45 ) ) )
return - V_44 ;
F_3 ( V_5 , V_18 , 1 , L_26 ,
3 , V_46 -> V_56 ) ;
for ( V_29 = 0 ; V_29 < 3 ; V_29 ++ ) {
V_2 = V_2 | V_46 -> V_56 [ V_29 ] ;
if ( V_29 < 2 )
V_2 = V_2 << 8 ;
}
F_3 ( V_5 , V_18 , 1 , L_27 , V_2 ) ;
switch ( V_2 ) {
case V_26 :
memcpy ( V_46 -> V_56 , V_8 -> V_23 , 128 ) ;
if ( F_19 ( V_38 , V_46 , sizeof ( struct V_45 ) ) )
return - V_44 ;
break;
case V_35 :
memcpy ( V_46 -> V_56 , V_8 -> V_23 , 128 ) ;
if ( F_19 ( V_38 , V_46 , sizeof ( struct V_45 ) ) )
return - V_44 ;
break;
}
return 0 ;
}
static int F_24 ( struct V_7 * V_8 , struct V_45 * V_46 , struct V_45 * V_57 , T_3 V_3 )
{
if ( V_8 -> V_58 & V_59 ) {
V_57 -> V_56 [ 2 ] = V_46 -> V_56 [ 1 ] ;
V_57 -> V_56 [ 3 ] = V_46 -> V_56 [ 2 ] ;
} else {
if ( V_3 > 247 ) {
F_3 ( V_5 , V_15 , 1 , L_28 ) ;
return - V_19 ;
}
V_57 -> V_56 [ 0 ] = ( V_3 & 0xff ) + 7 ;
V_57 -> V_56 [ 1 ] = 0x40 ;
V_57 -> V_56 [ 2 ] = 0x03 ;
V_57 -> V_56 [ 3 ] = 0x00 ;
V_57 -> V_56 [ 4 ] = 0x03 ;
V_57 -> V_56 [ 5 ] = V_3 & 0xff ;
V_57 -> V_56 [ 6 ] = 0x00 ;
memcpy ( & V_57 -> V_56 [ 7 ] , & V_46 -> V_56 [ 4 ] , V_3 ) ;
}
return 0 ;
}
static int F_25 ( struct V_7 * V_8 , struct V_45 * V_57 , T_1 V_3 , T_1 V_12 )
{
if ( ( F_15 ( V_8 , V_57 -> V_56 , V_3 , V_57 -> V_56 , V_12 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_29 ) ;
F_3 ( V_5 , V_18 , 1 , L_30 ) ;
F_26 ( V_8 ) ;
return - V_19 ;
}
F_3 ( V_5 , V_18 , 1 , L_31 ) ;
return 0 ;
}
static T_3 F_27 ( T_1 * V_60 )
{
T_1 V_61 = 0 , V_62 = 0 , V_63 = 0 ;
T_3 V_3 = 0 ;
V_61 = V_60 [ 0 ] ;
F_3 ( V_5 , V_6 , 1 , L_32 , V_61 ) ;
if ( V_61 < 0x80 ) {
V_3 = V_61 & 0x7f ;
F_3 ( V_5 , V_6 , 1 , L_33 , V_3 ) ;
} else {
V_62 = V_61 & 0x7f ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
V_3 = V_3 << 8 ;
V_3 += V_60 [ V_63 + 1 ] ;
F_3 ( V_5 , V_6 , 1 , L_34 , V_3 ) ;
}
}
return V_3 ;
}
static int F_28 ( T_1 * V_56 , T_3 V_3 , T_3 V_64 )
{
T_3 V_29 ;
F_3 ( V_5 , V_6 , 0 , L_35 ) ;
for ( V_29 = V_64 ; V_29 < V_3 ; V_29 ++ )
F_3 ( V_5 , V_6 , 0 , L_36 , V_56 [ V_29 ] ) ;
F_3 ( V_5 , V_6 , 0 , L_17 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 , struct V_45 * V_46 , struct V_45 * V_57 , T_1 V_12 , T_1 V_65 )
{
T_3 V_3 = 0 ;
T_1 V_66 = 8 ;
V_3 = F_27 ( & V_46 -> V_56 [ 3 ] ) ;
F_3 ( V_5 , V_6 , 1 , L_37 , V_3 ) ;
F_28 ( & V_46 -> V_56 [ 4 ] , V_3 , 0 ) ;
memset ( V_57 -> V_56 , '\0' , V_3 ) ;
F_24 ( V_8 , V_46 , V_57 , V_3 ) ;
F_2 ( V_57 -> V_56 , V_57 -> V_56 [ 0 ] ) ;
F_28 ( V_57 -> V_56 , ( V_3 + V_66 ) , 0 ) ;
F_25 ( V_8 , V_57 , ( V_3 + V_66 ) , V_12 ) ;
return 0 ;
}
static int F_30 ( struct V_7 * V_8 , struct V_45 * V_46 , struct V_45 * V_57 )
{
int V_67 = 0 ;
if ( V_67 ) {
if ( ( F_29 ( V_8 , V_46 , V_57 , 1 , V_24 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_38 ) ;
return - V_19 ;
}
F_3 ( V_5 , V_15 , 1 , L_39 ) ;
}
if ( ! V_67 ) {
if ( ( F_29 ( V_8 , V_46 , V_57 , 0 , V_68 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_38 ) ;
return - V_19 ;
}
F_3 ( V_5 , V_18 , 1 , L_40 ) ;
}
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_45 * V_46 , void T_2 * V_38 )
{
int V_29 ;
T_3 V_2 ;
struct V_45 * V_57 ;
int V_69 = 0 ;
V_57 = F_32 ( sizeof( * V_57 ) , V_70 ) ;
if ( ! V_57 )
return - V_71 ;
F_3 ( V_5 , V_6 , 1 , L_41 ) ;
if ( F_23 ( V_46 , V_38 , sizeof ( struct V_45 ) ) ) {
V_69 = - V_44 ;
goto V_72;
}
V_2 = 0 ;
for ( V_29 = 0 ; V_29 < 3 ; V_29 ++ ) {
V_2 = V_2 | V_46 -> V_56 [ V_29 ] ;
if ( V_29 < 2 )
V_2 = V_2 << 8 ;
}
F_3 ( V_5 , V_6 , 1 , L_42 , V_2 ) ;
switch ( V_2 ) {
case V_73 :
F_3 ( V_5 , V_6 , 1 , L_43 ) ;
if ( ( F_29 ( V_8 , V_46 , V_57 , 0 , 0 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_44 ) ;
V_69 = - 1 ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_45 ) ;
break;
case V_74 :
F_3 ( V_5 , V_14 , 1 , L_46 ) ;
if ( ( F_30 ( V_8 , V_46 , V_57 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_47 ) ;
V_69 = - 1 ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_48 ) ;
break;
case V_75 :
F_3 ( V_5 , V_14 , 1 , L_49 ) ;
if ( ( F_16 ( V_8 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_50 ) ;
V_69 = - 1 ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_51 ) ;
break;
case V_76 :
F_3 ( V_5 , V_14 , 1 , L_52 ) ;
if ( ( F_17 ( V_8 ) ) < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_53 ) ;
V_69 = - 1 ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_54 ) ;
break;
}
V_72:
F_33 ( V_57 ) ;
return V_69 ;
}
static long F_34 ( struct V_77 * V_77 , unsigned int V_78 , unsigned long V_79 )
{
struct V_80 * V_81 ;
struct V_7 * V_8 ;
struct V_48 * V_49 ;
struct V_36 * V_37 ;
struct V_45 * V_46 ;
void T_2 * V_38 = ( void T_2 * ) V_79 ;
int V_69 = 0 ;
F_6 ( & V_82 ) ;
V_81 = V_77 -> V_83 ;
V_8 = (struct V_7 * ) V_81 -> V_84 ;
V_46 = F_32 ( sizeof ( struct V_45 ) , V_70 ) ;
V_49 = F_32 ( sizeof ( struct V_48 ) , V_70 ) ;
V_37 = F_32 ( sizeof ( struct V_36 ) , V_70 ) ;
if ( ! V_46 || ! V_49 || ! V_37 ) {
V_69 = - V_71 ;
goto V_72;
}
switch ( V_78 ) {
case V_85 :
F_3 ( V_5 , V_14 , 1 , L_55 ) ;
V_69 = F_31 ( V_8 , V_46 , V_38 ) ;
if ( V_69 < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_56 ) ;
goto V_72;
}
break;
case V_86 :
F_3 ( V_5 , V_14 , 1 , L_57 ) ;
V_69 = F_22 ( V_8 , V_46 , V_38 ) ;
if ( V_69 < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_58 ) ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_59 ) ;
break;
case V_87 :
F_3 ( V_5 , V_15 , 1 , L_60 ) ;
F_35 ( V_8 ) ;
F_8 ( 4000 ) ;
break;
case V_88 :
F_3 ( V_5 , V_14 , 1 , L_61 ) ;
V_69 = F_21 ( V_8 , V_49 , V_38 ) ;
if ( V_69 < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_62 ) ;
V_69 = - 1 ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_63 ) ;
break;
case V_89 :
F_3 ( V_5 , V_14 , 1 , L_64 ) ;
V_69 = F_18 ( V_8 , V_37 , V_38 ) ;
if ( V_69 < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_65 ) ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_66 ) ;
break;
case V_90 :
F_3 ( V_5 , V_14 , 1 , L_67 ) ;
V_69 = F_20 ( V_8 , V_46 , V_38 ) ;
if ( V_69 < 0 ) {
F_3 ( V_5 , V_15 , 1 , L_68 ) ;
goto V_72;
}
F_3 ( V_5 , V_14 , 1 , L_69 ) ;
break;
default:
V_69 = - V_47 ;
}
V_72:
F_33 ( V_46 ) ;
F_33 ( V_49 ) ;
F_33 ( V_37 ) ;
F_14 ( & V_82 ) ;
return V_69 ;
}
static int F_36 ( struct V_91 * V_91 , struct V_77 * V_77 )
{
F_3 ( V_5 , V_6 , 1 , L_70 , V_77 ) ;
return 0 ;
}
static int F_37 ( struct V_91 * V_91 , struct V_77 * V_77 )
{
F_3 ( V_5 , V_6 , 1 , L_71 ) ;
return 0 ;
}
static T_4 F_38 ( struct V_77 * V_77 , char T_2 * V_92 , T_5 V_3 , T_6 * V_64 )
{
F_3 ( V_5 , V_6 , 1 , L_72 ) ;
return 0 ;
}
static T_4 F_39 ( struct V_77 * V_77 , const char T_2 * V_92 , T_5 V_3 , T_6 * V_64 )
{
F_3 ( V_5 , V_6 , 1 , L_73 ) ;
return 0 ;
}
struct V_80 * F_40 ( struct V_7 * V_93 , struct V_94 * V_94 )
{
struct V_80 * V_81 ;
F_3 ( V_5 , V_15 , 1 , L_74 ) ;
if ( F_41 ( V_94 , & V_81 , & V_95 , V_93 ,
V_96 , 0 ) == 0 ) {
V_93 -> V_97 = V_81 ;
return V_93 -> V_97 ;
}
return NULL ;
}
