int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_5 ;
return V_6 -> V_8 ? V_4 -> V_9 : 0 ;
}
int F_2 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_5 ;
if ( F_3 ( V_10 ) && V_6 -> V_8 )
return V_4 -> V_9 ;
else
return 0 ;
}
int F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
void * V_13 , void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
if ( ! F_3 ( V_10 ) )
return - V_15 ;
F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
return F_7 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_17 , 0 , - 1 ) ;
}
int F_8 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
const void * V_13 , const void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
int V_18 ;
if ( ! F_3 ( V_10 ) )
return - V_15 ;
F_9 ( V_5 ) ;
F_6 ( V_5 ) ;
V_18 = F_10 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_17 , 0 , - 1 ) ;
V_5 -> V_16 . V_17 . V_19 &= V_20 ;
if ( F_3 ( V_21 ) )
V_5 -> V_16 . V_22 . V_23 . V_24 |= V_25 ;
return V_18 ;
}
int F_11 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
void * V_13 , void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_26 * V_22 ;
int V_18 ;
if ( ! F_3 ( V_21 ) )
return - V_15 ;
V_22 = & V_5 -> V_16 . V_22 ;
F_5 ( V_5 ) ;
if ( F_12 () ) {
V_18 = F_13 ( V_11 , V_12 , V_13 , V_14 , V_22 ) ;
} else {
F_6 ( V_5 ) ;
memcpy ( & V_22 -> V_27 . V_28 , V_29 , sizeof( V_29 ) ) ;
V_18 = F_7 ( & V_11 , & V_12 , & V_13 , & V_14 , V_22 , 0 , - 1 ) ;
}
return V_18 ;
}
int F_14 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
const void * V_13 , const void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_26 * V_22 ;
int V_18 ;
if ( ! F_3 ( V_21 ) )
return - V_15 ;
if ( ( V_11 != 0 ) || ( V_12 < V_30 ) )
return - V_31 ;
V_22 = & V_5 -> V_16 . V_22 ;
F_9 ( V_5 ) ;
if ( F_3 ( V_32 ) )
V_18 = F_15 ( V_13 , V_14 , V_22 ) ;
else
V_18 = F_10 ( & V_11 , & V_12 , & V_13 , & V_14 , V_22 , 0 , - 1 ) ;
if ( V_18 )
F_16 ( & V_5 -> V_16 ) ;
V_22 -> V_27 . V_19 &= V_20 ;
V_22 -> V_23 . V_24 &= V_33 ;
memset ( & V_22 -> V_23 . V_34 , 0 , 48 ) ;
return V_18 ;
}
static inline unsigned short F_17 ( unsigned short V_35 )
{
unsigned int V_36 ;
V_36 = ~ V_35 ;
V_36 = ( V_36 | ( V_36 >> 1 ) ) & 0x5555 ;
V_36 = ( V_36 | ( V_36 >> 1 ) ) & 0x3333 ;
V_36 = ( V_36 | ( V_36 >> 2 ) ) & 0x0f0f ;
V_36 = ( V_36 | ( V_36 >> 4 ) ) & 0x00ff ;
return V_36 ;
}
static inline T_2 F_18 ( struct V_37 * V_17 )
{
struct V_38 * V_39 ;
T_2 V_40 = ( V_17 -> V_41 >> 11 ) & 7 ;
T_2 V_35 = ( unsigned long ) V_17 -> V_35 ;
T_2 V_42 ;
T_2 V_18 = 0xffff0000u ;
int V_43 ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ , V_35 >>= 1 ) {
if ( V_35 & 0x1 ) {
V_39 = F_19 ( V_17 , ( V_43 - V_40 ) & 7 ) ;
switch ( V_39 -> V_44 & 0x7fff ) {
case 0x7fff :
V_42 = V_45 ;
break;
case 0x0000 :
if ( ! V_39 -> V_46 [ 0 ] &&
! V_39 -> V_46 [ 1 ] &&
! V_39 -> V_46 [ 2 ] &&
! V_39 -> V_46 [ 3 ] )
V_42 = V_47 ;
else
V_42 = V_45 ;
break;
default:
if ( V_39 -> V_46 [ 3 ] & 0x8000 )
V_42 = V_48 ;
else
V_42 = V_45 ;
break;
}
} else {
V_42 = V_49 ;
}
V_18 |= V_42 << ( 2 * V_43 ) ;
}
return V_18 ;
}
void
F_20 ( struct V_50 * V_51 , struct V_1 * V_52 )
{
struct V_37 * V_17 = & V_52 -> V_7 . V_5 . V_16 . V_17 ;
struct V_53 * V_54 = (struct V_53 * ) & V_51 -> V_55 [ 0 ] ;
struct V_38 * V_56 = (struct V_38 * ) & V_17 -> V_55 [ 0 ] ;
int V_43 ;
V_51 -> V_57 = V_17 -> V_57 | 0xffff0000u ;
V_51 -> V_41 = V_17 -> V_41 | 0xffff0000u ;
V_51 -> V_35 = F_18 ( V_17 ) ;
#ifdef F_21
V_51 -> V_58 = V_17 -> V_59 ;
V_51 -> V_60 = V_17 -> V_61 ;
V_51 -> V_62 = F_22 ( V_52 ) -> V_63 ;
if ( V_52 == V_64 ) {
F_23 ( V_65 , V_51 -> V_66 ) ;
} else {
V_51 -> V_66 = V_52 -> V_7 . V_65 ;
}
V_51 -> V_66 |= 0xffff0000 ;
#else
V_51 -> V_58 = V_17 -> V_58 ;
V_51 -> V_62 = ( V_67 ) V_17 -> V_62 | ( ( T_2 ) V_17 -> V_68 << 16 ) ;
V_51 -> V_60 = V_17 -> V_60 ;
V_51 -> V_66 = V_17 -> V_66 ;
#endif
for ( V_43 = 0 ; V_43 < 8 ; ++ V_43 )
memcpy ( & V_54 [ V_43 ] , & V_56 [ V_43 ] , sizeof( V_54 [ 0 ] ) ) ;
}
void F_24 ( struct V_1 * V_52 ,
const struct V_50 * V_51 )
{
struct V_37 * V_17 = & V_52 -> V_7 . V_5 . V_16 . V_17 ;
struct V_53 * V_56 = (struct V_53 * ) & V_51 -> V_55 [ 0 ] ;
struct V_38 * V_54 = (struct V_38 * ) & V_17 -> V_55 [ 0 ] ;
int V_43 ;
V_17 -> V_57 = V_51 -> V_57 ;
V_17 -> V_41 = V_51 -> V_41 ;
V_17 -> V_35 = F_17 ( V_51 -> V_35 ) ;
V_17 -> V_68 = ( V_67 ) ( ( T_2 ) V_51 -> V_62 >> 16 ) ;
#ifdef F_21
V_17 -> V_59 = V_51 -> V_58 ;
V_17 -> V_61 = V_51 -> V_60 ;
#else
V_17 -> V_58 = V_51 -> V_58 ;
V_17 -> V_62 = ( V_51 -> V_62 & 0xffff ) ;
V_17 -> V_60 = V_51 -> V_60 ;
V_17 -> V_66 = V_51 -> V_66 ;
#endif
for ( V_43 = 0 ; V_43 < 8 ; ++ V_43 )
memcpy ( & V_54 [ V_43 ] , & V_56 [ V_43 ] , sizeof( V_56 [ 0 ] ) ) ;
}
int F_25 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
void * V_13 , void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_50 V_51 ;
F_5 ( V_5 ) ;
if ( ! F_3 ( V_69 ) )
return F_26 ( V_2 , V_4 , V_11 , V_12 , V_13 , V_14 ) ;
if ( ! F_3 ( V_10 ) )
return F_7 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_70 , 0 ,
- 1 ) ;
F_6 ( V_5 ) ;
if ( V_13 && V_11 == 0 && V_12 == sizeof( V_51 ) ) {
F_20 ( V_13 , V_2 ) ;
return 0 ;
}
F_20 ( & V_51 , V_2 ) ;
return F_7 ( & V_11 , & V_12 , & V_13 , & V_14 , & V_51 , 0 , - 1 ) ;
}
int F_27 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
const void * V_13 , const void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_50 V_51 ;
int V_18 ;
F_9 ( V_5 ) ;
F_6 ( V_5 ) ;
if ( ! F_3 ( V_69 ) )
return F_28 ( V_2 , V_4 , V_11 , V_12 , V_13 , V_14 ) ;
if ( ! F_3 ( V_10 ) )
return F_10 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_70 , 0 ,
- 1 ) ;
if ( V_11 > 0 || V_12 < sizeof( V_51 ) )
F_20 ( & V_51 , V_2 ) ;
V_18 = F_10 ( & V_11 , & V_12 , & V_13 , & V_14 , & V_51 , 0 , - 1 ) ;
if ( ! V_18 )
F_24 ( V_2 , & V_51 ) ;
if ( F_3 ( V_21 ) )
V_5 -> V_16 . V_22 . V_23 . V_24 |= V_71 ;
return V_18 ;
}
int F_29 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
struct V_1 * V_52 = V_64 ;
struct V_5 * V_5 = & V_52 -> V_7 . V_5 ;
int V_76 ;
V_76 = V_5 -> V_8 ;
if ( V_76 )
V_76 = ! F_25 ( V_52 , NULL ,
0 , sizeof( struct V_50 ) ,
V_75 , NULL ) ;
return V_76 ;
}
