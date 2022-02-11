static int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 , V_8 ;
V_8 = 0 ;
F_3 (i, active_scan_mask, AD7923_MAX_CHAN) {
V_7 = V_9 | F_4 ( V_6 ) |
F_5 ( V_10 ) |
V_5 -> V_11 ;
V_7 <<= V_12 ;
V_5 -> V_13 [ V_8 ++ ] = F_6 ( V_7 ) ;
}
V_5 -> V_14 [ 0 ] . V_13 = & V_5 -> V_13 [ 0 ] ;
V_5 -> V_14 [ 0 ] . V_8 = V_8 ;
V_5 -> V_14 [ 0 ] . V_15 = 1 ;
F_7 ( & V_5 -> V_16 ) ;
F_8 ( & V_5 -> V_14 [ 0 ] , & V_5 -> V_16 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
V_5 -> V_14 [ V_6 + 1 ] . V_17 = & V_5 -> V_17 [ V_6 ] ;
V_5 -> V_14 [ V_6 + 1 ] . V_8 = 2 ;
V_5 -> V_14 [ V_6 + 1 ] . V_15 = 1 ;
F_8 ( & V_5 -> V_14 [ V_6 + 1 ] , & V_5 -> V_16 ) ;
}
V_5 -> V_14 [ V_6 + 1 ] . V_15 = 0 ;
return 0 ;
}
static T_1 F_9 ( int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_22 = 0 ;
int V_23 ;
V_23 = F_10 ( V_5 -> V_24 , & V_5 -> V_16 ) ;
if ( V_23 )
goto V_25;
if ( V_2 -> V_26 ) {
V_22 = F_11 () ;
memcpy ( ( V_27 * ) V_5 -> V_17 + V_2 -> V_28 - sizeof( T_2 ) ,
& V_22 , sizeof( V_22 ) ) ;
}
F_12 ( V_2 , ( V_27 * ) V_5 -> V_17 ) ;
V_25:
F_13 ( V_2 -> V_29 ) ;
return V_30 ;
}
static int F_14 ( struct V_4 * V_5 , unsigned V_31 )
{
int V_32 , V_7 ;
V_7 = V_9 | F_4 ( V_31 ) |
F_5 ( V_10 ) |
V_5 -> V_11 ;
V_7 <<= V_12 ;
V_5 -> V_13 [ 0 ] = F_6 ( V_7 ) ;
V_32 = F_10 ( V_5 -> V_24 , & V_5 -> V_33 ) ;
if ( V_32 )
return V_32 ;
return F_15 ( V_5 -> V_17 [ 0 ] ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_34 ;
V_34 = F_17 ( V_5 -> V_35 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 /= 1000 ;
if ( ! ( V_5 -> V_11 & V_36 ) )
V_34 *= 2 ;
return V_34 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_37 const * V_38 ,
int * V_39 ,
int * V_40 ,
long V_41 )
{
int V_32 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_41 ) {
case V_42 :
F_19 ( & V_2 -> V_43 ) ;
if ( F_20 ( V_2 ) )
V_32 = - V_44 ;
else
V_32 = F_14 ( V_5 , V_38 -> V_45 ) ;
F_21 ( & V_2 -> V_43 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_38 -> V_45 == F_22 ( V_32 , 12 , 4 ) )
* V_39 = F_22 ( V_32 , 0 , 12 ) ;
else
return - V_46 ;
return V_47 ;
case V_48 :
V_32 = F_16 ( V_5 ) ;
if ( V_32 < 0 )
return V_32 ;
* V_39 = V_32 ;
* V_40 = V_38 -> V_49 . V_50 ;
return V_51 ;
}
return - V_52 ;
}
static int F_23 ( struct V_53 * V_24 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
const struct V_54 * V_55 ;
int V_32 ;
V_2 = F_24 ( & V_24 -> V_56 , sizeof( * V_5 ) ) ;
if ( V_2 == NULL )
return - V_57 ;
V_5 = F_2 ( V_2 ) ;
F_25 ( V_24 , V_2 ) ;
V_5 -> V_24 = V_24 ;
V_5 -> V_11 = V_58 | V_36 |
F_26 ( V_59 ) ;
V_55 = & V_54 [ F_27 ( V_24 ) -> V_60 ] ;
V_2 -> V_61 = F_27 ( V_24 ) -> V_61 ;
V_2 -> V_56 . V_62 = & V_24 -> V_56 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_55 -> V_65 ;
V_2 -> V_66 = V_55 -> V_66 ;
V_2 -> V_55 = & V_67 ;
V_5 -> V_68 [ 0 ] . V_13 = & V_5 -> V_13 [ 0 ] ;
V_5 -> V_68 [ 0 ] . V_8 = 2 ;
V_5 -> V_68 [ 0 ] . V_15 = 1 ;
V_5 -> V_68 [ 1 ] . V_17 = & V_5 -> V_17 [ 0 ] ;
V_5 -> V_68 [ 1 ] . V_8 = 2 ;
F_7 ( & V_5 -> V_33 ) ;
F_8 ( & V_5 -> V_68 [ 0 ] , & V_5 -> V_33 ) ;
F_8 ( & V_5 -> V_68 [ 1 ] , & V_5 -> V_33 ) ;
V_5 -> V_35 = F_28 ( & V_24 -> V_56 , L_1 ) ;
if ( F_29 ( V_5 -> V_35 ) )
return F_30 ( V_5 -> V_35 ) ;
V_32 = F_31 ( V_5 -> V_35 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_32 ( V_2 , NULL ,
& F_9 , NULL ) ;
if ( V_32 )
goto V_69;
V_32 = F_33 ( V_2 ) ;
if ( V_32 )
goto V_70;
return 0 ;
V_70:
F_34 ( V_2 ) ;
V_69:
F_35 ( V_5 -> V_35 ) ;
return V_32 ;
}
static int F_36 ( struct V_53 * V_24 )
{
struct V_1 * V_2 = F_37 ( V_24 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_38 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_5 -> V_35 ) ;
return 0 ;
}
