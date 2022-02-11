static unsigned long F_1 ( struct V_1 * V_2 , long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
V_3 <<= 4 ;
V_3 &= ( ( 1 << ( ( V_5 -> V_7 & 0x1f ) + 11 ) ) - 1 ) << 7 | 0x70 ;
V_6 = V_5 -> V_7 & 0xfffffffffffc0000ULL ;
V_6 |= V_3 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
long V_8 = F_4 ( V_2 , 4 ) ;
long V_3 = F_4 ( V_2 , 5 ) ;
T_1 V_9 [ 2 * 8 ] ;
T_1 * V_10 ;
unsigned long V_6 , V_11 ;
long int V_12 ;
V_11 = V_3 & 7 ;
V_3 &= ~ 7UL ;
V_6 = F_1 ( V_2 , V_3 ) ;
F_5 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
F_6 ( V_9 , ( void V_16 * ) V_6 , sizeof( V_9 ) ) ;
V_10 = V_9 ;
V_12 = V_17 ;
if ( F_7 ( ( V_8 & V_18 ) == 0 ) ) {
for ( V_11 = 0 ; ; ++ V_11 ) {
if ( V_11 == 8 )
goto V_19;
if ( ( F_8 ( * V_10 ) & V_20 ) == 0 )
break;
V_10 += 2 ;
}
} else {
V_10 += V_11 * 2 ;
if ( * V_10 & V_20 )
goto V_19;
}
V_10 [ 0 ] = F_9 ( F_4 ( V_2 , 6 ) ) ;
V_10 [ 1 ] = F_9 ( F_4 ( V_2 , 7 ) ) ;
V_6 += V_11 * V_21 ;
F_10 ( ( void V_16 * ) V_6 , V_10 , V_21 ) ;
F_11 ( V_2 , 4 , V_3 | V_11 ) ;
V_12 = V_22 ;
V_19:
F_12 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
F_11 ( V_2 , 3 , V_12 ) ;
return V_23 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned long V_8 = F_4 ( V_2 , 4 ) ;
unsigned long V_3 = F_4 ( V_2 , 5 ) ;
unsigned long V_24 = F_4 ( V_2 , 6 ) ;
unsigned long V_25 = 0 , V_9 , V_26 ;
unsigned long V_27 [ 2 ] ;
long int V_12 ;
V_9 = F_1 ( V_2 , V_3 ) ;
F_5 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
F_6 ( V_27 , ( void V_16 * ) V_9 , sizeof( V_27 ) ) ;
V_27 [ 0 ] = F_8 ( ( V_28 T_1 ) V_27 [ 0 ] ) ;
V_27 [ 1 ] = F_8 ( ( V_28 T_1 ) V_27 [ 1 ] ) ;
V_12 = V_29 ;
if ( ( V_27 [ 0 ] & V_20 ) == 0 ||
( ( V_8 & V_30 ) && ( V_27 [ 0 ] & ~ 0x7fUL ) != V_24 ) ||
( ( V_8 & V_31 ) && ( V_27 [ 0 ] & V_24 ) != 0 ) )
goto V_19;
F_10 ( ( void V_16 * ) V_9 , & V_25 , sizeof( V_25 ) ) ;
V_26 = F_14 ( V_27 [ 0 ] , V_27 [ 1 ] , V_3 ) ;
V_2 -> V_14 . V_32 . V_33 ( V_2 , V_26 , V_26 & 1 ? true : false ) ;
V_12 = V_22 ;
F_11 ( V_2 , 4 , V_27 [ 0 ] ) ;
F_11 ( V_2 , 5 , V_27 [ 1 ] ) ;
V_19:
F_12 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
F_11 ( V_2 , 3 , V_12 ) ;
return V_23 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_11 ;
int V_34 = 4 ;
int V_12 = V_22 ;
F_5 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
for ( V_11 = 0 ; V_11 < V_35 ; V_11 ++ ) {
unsigned long V_36 = F_4 ( V_2 , V_34 + ( 2 * V_11 ) ) ;
unsigned long V_37 = F_4 ( V_2 , V_34 + ( 2 * V_11 ) + 1 ) ;
unsigned long V_9 , V_26 , V_8 ;
unsigned long V_27 [ 2 ] ;
unsigned long V_25 = 0 ;
if ( ( V_36 & V_38 ) == V_39 ) {
break;
} else if ( ( V_36 & V_38 ) !=
V_40 ) {
V_12 = V_41 ;
break;
}
V_36 &= V_42 | V_43 ;
V_36 |= V_44 ;
if ( ( V_36 & V_45 ) &&
( V_36 & V_46 ) ) {
V_36 |= V_47 ;
F_11 ( V_2 , V_34 + ( 2 * V_11 ) , V_36 ) ;
V_12 = V_41 ;
break;
}
V_9 = F_1 ( V_2 , V_36 & V_42 ) ;
F_6 ( V_27 , ( void V_16 * ) V_9 , sizeof( V_27 ) ) ;
V_27 [ 0 ] = F_8 ( ( V_28 T_1 ) V_27 [ 0 ] ) ;
V_27 [ 1 ] = F_8 ( ( V_28 T_1 ) V_27 [ 1 ] ) ;
V_8 = ( V_36 & V_43 ) >> 26 ;
if ( ( V_27 [ 0 ] & V_20 ) == 0 ||
( ( V_8 & V_30 ) && ( V_27 [ 0 ] & ~ 0x7fUL ) != V_37 ) ||
( ( V_8 & V_31 ) && ( V_27 [ 0 ] & V_37 ) != 0 ) ) {
V_36 |= V_48 ;
} else {
F_10 ( ( void V_16 * ) V_9 , & V_25 , sizeof( V_25 ) ) ;
V_26 = F_14 ( V_27 [ 0 ] , V_27 [ 1 ] ,
V_36 & V_42 ) ;
V_2 -> V_14 . V_32 . V_33 ( V_2 , V_26 , V_26 & 1 ? true : false ) ;
V_36 |= V_49 ;
V_36 |= ( V_27 [ 1 ] & ( V_50 | V_51 ) ) << 43 ;
}
F_11 ( V_2 , V_34 + ( 2 * V_11 ) , V_36 ) ;
}
F_12 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
F_11 ( V_2 , 3 , V_12 ) ;
return V_23 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned long V_8 = F_4 ( V_2 , 4 ) ;
unsigned long V_3 = F_4 ( V_2 , 5 ) ;
unsigned long V_24 = F_4 ( V_2 , 6 ) ;
unsigned long V_26 , V_9 , V_52 , V_25 ;
unsigned long V_27 [ 2 ] ;
long int V_12 ;
V_9 = F_1 ( V_2 , V_3 ) ;
F_5 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
F_6 ( V_27 , ( void V_16 * ) V_9 , sizeof( V_27 ) ) ;
V_27 [ 0 ] = F_8 ( ( V_28 T_1 ) V_27 [ 0 ] ) ;
V_27 [ 1 ] = F_8 ( ( V_28 T_1 ) V_27 [ 1 ] ) ;
V_12 = V_29 ;
if ( ( V_27 [ 0 ] & V_20 ) == 0 ||
( ( V_8 & V_30 ) && ( V_27 [ 0 ] & ~ 0x7fUL ) != V_24 ) )
goto V_19;
V_25 = V_27 [ 0 ] ;
V_52 = V_27 [ 1 ] ;
V_52 &= ~ ( V_53 | V_54 | V_55 | V_56 |
V_57 ) ;
V_52 |= ( V_8 << 55 ) & V_53 ;
V_52 |= ( V_8 << 48 ) & V_56 ;
V_52 |= V_8 & ( V_54 | V_55 | V_57 ) ;
V_27 [ 1 ] = V_52 ;
V_26 = F_14 ( V_25 , V_52 , V_3 ) ;
V_2 -> V_14 . V_32 . V_33 ( V_2 , V_26 , V_26 & 1 ? true : false ) ;
V_27 [ 0 ] = ( V_28 V_58 ) F_9 ( V_27 [ 0 ] ) ;
V_27 [ 1 ] = ( V_28 V_58 ) F_9 ( V_27 [ 1 ] ) ;
F_10 ( ( void V_16 * ) V_9 , V_27 , sizeof( V_27 ) ) ;
V_12 = V_22 ;
V_19:
F_12 ( & V_2 -> V_13 -> V_14 . V_15 ) ;
F_11 ( V_2 , 3 , V_12 ) ;
return V_23 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_59 = F_4 ( V_2 , 4 ) ;
unsigned long V_60 = F_4 ( V_2 , 5 ) ;
unsigned long V_61 = F_4 ( V_2 , 6 ) ;
long V_62 ;
V_62 = F_18 ( V_2 , V_59 , V_60 , V_61 ) ;
if ( V_62 == V_63 )
return V_64 ;
F_11 ( V_2 , 3 , V_62 ) ;
return V_23 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_65 )
{
long V_62 = F_20 ( V_2 , V_65 ) ;
F_11 ( V_2 , 3 , V_62 ) ;
return V_23 ;
}
int F_21 ( struct V_1 * V_2 , unsigned long V_65 )
{
int V_62 , V_66 ;
if ( V_65 <= V_67 &&
! F_22 ( V_65 / 4 , V_2 -> V_13 -> V_14 . V_68 ) )
return V_64 ;
switch ( V_65 ) {
case V_69 :
return F_3 ( V_2 ) ;
case V_70 :
return F_13 ( V_2 ) ;
case V_71 :
return F_16 ( V_2 ) ;
case V_72 :
return F_15 ( V_2 ) ;
case V_73 :
return F_17 ( V_2 ) ;
case V_74 :
F_23 ( V_2 , F_24 ( V_2 ) | V_75 ) ;
F_25 ( V_2 ) ;
F_26 ( V_76 , & V_2 -> V_77 ) ;
V_2 -> V_78 . V_79 ++ ;
return V_23 ;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( F_27 ( V_2 ) )
return F_19 ( V_2 , V_65 ) ;
break;
case V_86 :
if ( F_28 ( & V_2 -> V_13 -> V_14 . V_87 ) )
break;
V_66 = F_29 ( & V_2 -> V_13 -> V_88 ) ;
V_62 = F_30 ( V_2 ) ;
F_31 ( & V_2 -> V_13 -> V_88 , V_66 ) ;
if ( V_62 )
break;
F_11 ( V_2 , 3 , 0 ) ;
return V_23 ;
}
return V_64 ;
}
int F_32 ( unsigned long V_65 )
{
switch ( V_65 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
#ifdef F_33
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
#endif
return 1 ;
}
return 0 ;
}
void F_34 ( struct V_13 * V_13 )
{
int V_11 ;
unsigned int V_89 ;
for ( V_11 = 0 ; V_90 [ V_11 ] ; ++ V_11 ) {
V_89 = V_90 [ V_11 ] ;
F_35 ( ! F_32 ( V_89 ) ) ;
F_36 ( V_89 / 4 , V_13 -> V_14 . V_68 ) ;
}
}
