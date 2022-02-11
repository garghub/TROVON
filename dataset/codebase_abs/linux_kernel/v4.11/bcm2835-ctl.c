static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 ) ;
if ( V_2 -> V_5 == V_6 ) {
V_4 -> type = V_7 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 . integer . V_10 = V_11 ;
V_4 -> V_9 . integer . V_12 = V_13 ;
} else if ( V_2 -> V_5 == V_14 ) {
V_4 -> type = V_15 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 . integer . V_10 = 0 ;
V_4 -> V_9 . integer . V_12 = 1 ;
} else if ( V_2 -> V_5 == V_16 ) {
V_4 -> type = V_7 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 . integer . V_10 = 0 ;
V_4 -> V_9 . integer . V_12 = V_17 - 1 ;
}
F_2 ( L_2 ) ;
return 0 ;
}
static int F_3 ( struct V_18 * V_19 , int V_20 )
{
if ( V_19 -> V_21 == V_20 )
return 0 ;
if ( V_19 -> V_21 == V_22 ) {
V_19 -> V_23 = V_19 -> V_24 ;
F_2 ( L_3 , V_19 -> V_24 , V_19 -> V_23 ) ;
} else {
V_19 -> V_24 = V_19 -> V_23 ;
V_19 -> V_23 = 26214 ;
F_2 ( L_4 , V_19 -> V_24 , V_19 -> V_23 ) ;
}
V_19 -> V_21 = V_20 ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
F_7 ( ! V_19 && ! ( V_19 -> V_29 & V_30 ) ) ;
if ( V_2 -> V_5 == V_6 )
V_26 -> V_9 . integer . V_9 [ 0 ] = F_8 ( V_19 -> V_23 ) ;
else if ( V_2 -> V_5 == V_14 )
V_26 -> V_9 . integer . V_9 [ 0 ] = V_19 -> V_21 ;
else if ( V_2 -> V_5 == V_16 )
V_26 -> V_9 . integer . V_9 [ 0 ] = V_19 -> V_31 ;
F_9 ( & V_19 -> V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_32 = 0 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
if ( V_2 -> V_5 == V_6 ) {
F_2 ( L_5 , V_19 -> V_23 , ( int ) V_26 -> V_9 . integer . V_9 [ 0 ] ) ;
if ( V_19 -> V_21 == V_22 ) {
V_32 = 1 ;
goto V_33;
}
if ( V_32
|| ( V_26 -> V_9 . integer . V_9 [ 0 ] != F_8 ( V_19 -> V_23 ) ) ) {
V_19 -> V_23 = F_11 ( V_26 -> V_9 . integer . V_9 [ 0 ] ) ;
V_32 = 1 ;
}
} else if ( V_2 -> V_5 == V_14 ) {
F_2 ( L_6 ) ;
V_32 = F_3 ( V_19 , V_26 -> V_9 . integer . V_9 [ 0 ] ) ;
} else if ( V_2 -> V_5 == V_16 ) {
if ( V_26 -> V_9 . integer . V_9 [ 0 ] != V_19 -> V_31 ) {
V_19 -> V_31 = V_26 -> V_9 . integer . V_9 [ 0 ] ;
V_32 = 1 ;
}
}
if ( V_32 ) {
if ( F_12 ( V_19 ) )
F_13 ( V_34 L_7 ) ;
}
V_33:
F_9 ( & V_19 -> V_27 ) ;
return V_32 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_35 ;
V_4 -> V_8 = 1 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_36 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
V_26 -> V_9 . V_37 . V_38 [ V_36 ] =
( V_19 -> V_39 >> ( V_36 * 8 ) ) & 0xff ;
F_9 ( & V_19 -> V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
unsigned int V_40 = 0 ;
int V_36 , V_41 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
V_40 |= ( unsigned int ) V_26 -> V_9 . V_37 . V_38 [ V_36 ] << ( V_36 * 8 ) ;
V_41 = V_40 != V_19 -> V_39 ;
V_19 -> V_39 = V_40 ;
F_9 ( & V_19 -> V_27 ) ;
return V_41 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_35 ;
V_4 -> V_8 = 1 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
V_26 -> V_9 . V_37 . V_38 [ 0 ] = V_42 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_35 ;
V_4 -> V_8 = 1 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_36 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
V_26 -> V_9 . V_37 . V_38 [ V_36 ] =
( V_19 -> V_39 >> ( V_36 * 8 ) ) & 0xff ;
F_9 ( & V_19 -> V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
unsigned int V_40 = 0 ;
int V_36 , V_41 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
V_40 |= ( unsigned int ) V_26 -> V_9 . V_37 . V_38 [ V_36 ] << ( V_36 * 8 ) ;
V_41 = V_40 != V_19 -> V_39 ;
V_19 -> V_39 = V_40 ;
F_9 ( & V_19 -> V_27 ) ;
return V_41 ;
}
int F_22 ( struct V_18 * V_19 )
{
int V_43 ;
unsigned int V_44 ;
strcpy ( V_19 -> V_45 -> V_46 , L_8 ) ;
for ( V_44 = 0 ; V_44 < F_23 ( V_47 ) ; V_44 ++ ) {
V_43 = F_24 ( V_19 -> V_45 ,
F_25 ( & V_47 [ V_44 ] , V_19 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
for ( V_44 = 0 ; V_44 < F_23 ( V_48 ) ; V_44 ++ ) {
V_43 = F_24 ( V_19 -> V_45 ,
F_25 ( & V_48 [ V_44 ] , V_19 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
