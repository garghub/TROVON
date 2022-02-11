static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
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
return 0 ;
}
static int F_2 ( struct V_18 * V_19 , int V_20 )
{
if ( V_19 -> V_21 == V_20 )
return 0 ;
if ( V_19 -> V_21 == V_22 ) {
V_19 -> V_23 = V_19 -> V_24 ;
F_3 ( L_1 , V_19 -> V_24 , V_19 -> V_23 ) ;
} else {
V_19 -> V_24 = V_19 -> V_23 ;
V_19 -> V_23 = 26214 ;
F_3 ( L_2 , V_19 -> V_24 , V_19 -> V_23 ) ;
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
F_3 ( L_3 , V_19 -> V_23 , ( int ) V_26 -> V_9 . integer . V_9 [ 0 ] ) ;
if ( V_19 -> V_21 == V_22 ) {
V_32 = 1 ;
goto V_33;
}
if ( V_32 || ( V_26 -> V_9 . integer . V_9 [ 0 ] != F_8 ( V_19 -> V_23 ) ) ) {
V_19 -> V_23 = F_11 ( V_26 -> V_9 . integer . V_9 [ 0 ] ) ;
V_32 = 1 ;
}
} else if ( V_2 -> V_5 == V_14 ) {
F_3 ( L_4 ) ;
V_32 = F_2 ( V_19 , V_26 -> V_9 . integer . V_9 [ 0 ] ) ;
} else if ( V_2 -> V_5 == V_16 ) {
if ( V_26 -> V_9 . integer . V_9 [ 0 ] != V_19 -> V_31 ) {
V_19 -> V_31 = V_26 -> V_9 . integer . V_9 [ 0 ] ;
V_32 = 1 ;
}
}
if ( V_32 && F_12 ( V_19 ) )
F_13 ( V_19 -> V_34 -> V_35 , L_5 ) ;
V_33:
F_9 ( & V_19 -> V_27 ) ;
return V_32 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_36 ;
V_4 -> V_8 = 1 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_37 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
V_26 -> V_9 . V_38 . V_39 [ V_37 ] =
( V_19 -> V_40 >> ( V_37 * 8 ) ) & 0xff ;
F_9 ( & V_19 -> V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
unsigned int V_41 = 0 ;
int V_37 , V_42 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
V_41 |= ( unsigned int ) V_26 -> V_9 . V_38 . V_39 [ V_37 ] << ( V_37 * 8 ) ;
V_42 = V_41 != V_19 -> V_40 ;
V_19 -> V_40 = V_41 ;
F_9 ( & V_19 -> V_27 ) ;
return V_42 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_36 ;
V_4 -> V_8 = 1 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
V_26 -> V_9 . V_38 . V_39 [ 0 ] = V_43 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_36 ;
V_4 -> V_8 = 1 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_37 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
V_26 -> V_9 . V_38 . V_39 [ V_37 ] =
( V_19 -> V_40 >> ( V_37 * 8 ) ) & 0xff ;
F_9 ( & V_19 -> V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
unsigned int V_41 = 0 ;
int V_37 , V_42 ;
if ( F_6 ( & V_19 -> V_27 ) )
return - V_28 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
V_41 |= ( unsigned int ) V_26 -> V_9 . V_38 . V_39 [ V_37 ] << ( V_37 * 8 ) ;
V_42 = V_41 != V_19 -> V_40 ;
V_19 -> V_40 = V_41 ;
F_9 ( & V_19 -> V_27 ) ;
return V_42 ;
}
int F_22 ( struct V_18 * V_19 )
{
int V_44 ;
unsigned int V_45 ;
strcpy ( V_19 -> V_34 -> V_46 , L_6 ) ;
for ( V_45 = 0 ; V_45 < F_23 ( V_47 ) ; V_45 ++ ) {
V_44 = F_24 ( V_19 -> V_34 ,
F_25 ( & V_47 [ V_45 ] , V_19 ) ) ;
if ( V_44 < 0 )
return V_44 ;
}
for ( V_45 = 0 ; V_45 < F_23 ( V_48 ) ; V_45 ++ ) {
V_44 = F_24 ( V_19 -> V_34 ,
F_25 ( & V_48 [ V_45 ] , V_19 ) ) ;
if ( V_44 < 0 )
return V_44 ;
}
return 0 ;
}
int F_26 ( struct V_18 * V_19 )
{
int V_44 ;
unsigned int V_45 ;
strcpy ( V_19 -> V_34 -> V_46 , L_6 ) ;
for ( V_45 = 0 ; V_45 < F_23 ( V_49 ) ; V_45 ++ ) {
V_44 = F_24 ( V_19 -> V_34 ,
F_25 ( & V_49 [ V_45 ] ,
V_19 ) ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
int F_27 ( struct V_18 * V_19 )
{
int V_44 ;
unsigned int V_45 ;
strcpy ( V_19 -> V_34 -> V_46 , L_6 ) ;
for ( V_45 = 0 ; V_45 < F_23 ( V_50 ) ; V_45 ++ ) {
V_44 = F_24 ( V_19 -> V_34 ,
F_25 ( & V_50 [ V_45 ] , V_19 ) ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
