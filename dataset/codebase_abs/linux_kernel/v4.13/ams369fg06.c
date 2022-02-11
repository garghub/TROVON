static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 [ 1 ] ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 2 ,
. V_11 = V_5 ,
} ;
V_5 [ 0 ] = ( V_3 << 8 ) | V_4 ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
return F_4 ( V_2 -> V_12 , & V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char V_13 ,
unsigned char V_14 )
{
int V_15 = 0 ;
if ( V_13 != V_16 )
V_15 = F_1 ( V_2 , 0x70 , V_13 ) ;
if ( V_14 != V_17 )
V_15 = F_1 ( V_2 , 0x72 , V_14 ) ;
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 ,
const unsigned short * V_18 )
{
int V_15 = 0 , V_19 = 0 ;
while ( ( V_18 [ V_19 ] & V_20 ) != V_21 ) {
if ( ( V_18 [ V_19 ] & V_20 ) != V_22 ) {
V_15 = F_5 ( V_2 , V_18 [ V_19 ] , V_18 [ V_19 + 1 ] ) ;
if ( V_15 )
break;
} else {
F_7 ( V_18 [ V_19 + 1 ] ) ;
}
V_19 += 2 ;
}
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 ,
const unsigned int * gamma )
{
unsigned int V_19 = 0 ;
int V_15 = 0 ;
for ( V_19 = 0 ; V_19 < V_23 / 3 ; V_19 ++ ) {
V_15 = F_5 ( V_2 , 0x40 + V_19 , gamma [ V_19 ] ) ;
V_15 = F_5 ( V_2 , 0x50 + V_19 , gamma [ V_19 + 7 * 1 ] ) ;
V_15 = F_5 ( V_2 , 0x60 + V_19 , gamma [ V_19 + 7 * 2 ] ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_1 ) ;
goto V_25;
}
}
V_25:
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 , int V_26 )
{
int V_15 = 0 ;
int gamma = 0 ;
if ( ( V_26 >= 0 ) && ( V_26 <= 50 ) )
gamma = 0 ;
else if ( ( V_26 > 50 ) && ( V_26 <= 100 ) )
gamma = 1 ;
else if ( ( V_26 > 100 ) && ( V_26 <= 150 ) )
gamma = 2 ;
else if ( ( V_26 > 150 ) && ( V_26 <= 200 ) )
gamma = 3 ;
else if ( ( V_26 > 200 ) && ( V_26 <= 255 ) )
gamma = 4 ;
V_15 = F_8 ( V_2 , V_27 . V_28 [ gamma ] ) ;
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_15 , V_19 ;
static const unsigned short * V_29 [] = {
V_30 ,
V_31 ,
} ;
for ( V_19 = 0 ; V_19 < F_12 ( V_29 ) ; V_19 ++ ) {
V_15 = F_6 ( V_2 , V_29 [ V_19 ] ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_15 , V_19 ;
static const unsigned short * V_29 [] = {
V_31 ,
V_32 ,
} ;
for ( V_19 = 0 ; V_19 < F_12 ( V_29 ) ; V_19 ++ ) {
V_15 = F_6 ( V_2 , V_29 [ V_19 ] ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_15 , V_19 ;
static const unsigned short * V_29 [] = {
V_33 ,
V_34 ,
} ;
for ( V_19 = 0 ; V_19 < F_12 ( V_29 ) ; V_19 ++ ) {
V_15 = F_6 ( V_2 , V_29 [ V_19 ] ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_15 ( int V_35 )
{
return V_35 <= V_36 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_38 = V_2 -> V_41 ;
V_40 = V_2 -> V_40 ;
if ( V_38 -> V_42 ) {
V_38 -> V_42 ( V_2 -> V_43 , 1 ) ;
F_7 ( V_38 -> V_44 ) ;
}
if ( ! V_38 -> V_45 ) {
F_9 ( V_2 -> V_24 , L_2 ) ;
return - V_46 ;
}
V_38 -> V_45 ( V_2 -> V_43 ) ;
F_7 ( V_38 -> V_47 ) ;
V_15 = F_11 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_3 ) ;
return V_15 ;
}
V_15 = F_13 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_4 ) ;
return V_15 ;
}
V_15 = F_10 ( V_2 , V_40 -> V_48 . V_26 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_5 ) ;
return V_15 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_15 ;
struct V_37 * V_38 ;
V_38 = V_2 -> V_41 ;
V_15 = F_14 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_6 ) ;
return - V_49 ;
}
F_7 ( V_38 -> V_50 ) ;
if ( V_38 -> V_42 )
V_38 -> V_42 ( V_2 -> V_43 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_35 )
{
int V_15 = 0 ;
if ( F_15 ( V_35 ) &&
! F_15 ( V_2 -> V_35 ) )
V_15 = F_16 ( V_2 ) ;
else if ( ! F_15 ( V_35 ) &&
F_15 ( V_2 -> V_35 ) )
V_15 = F_17 ( V_2 ) ;
if ( ! V_15 )
V_2 -> V_35 = V_35 ;
return V_15 ;
}
static int F_19 ( struct V_51 * V_43 )
{
struct V_1 * V_2 = F_20 ( V_43 ) ;
return V_2 -> V_35 ;
}
static int F_21 ( struct V_51 * V_43 , int V_35 )
{
struct V_1 * V_2 = F_20 ( V_43 ) ;
if ( V_35 != V_52 && V_35 != V_53 &&
V_35 != V_36 ) {
F_9 ( V_2 -> V_24 , L_7 ) ;
return - V_46 ;
}
return F_18 ( V_2 , V_35 ) ;
}
static int F_22 ( struct V_39 * V_40 )
{
int V_15 = 0 ;
int V_26 = V_40 -> V_48 . V_26 ;
struct V_1 * V_2 = F_23 ( V_40 ) ;
if ( V_26 < V_54 ||
V_26 > V_40 -> V_48 . V_55 ) {
F_9 ( & V_40 -> V_24 , L_8 ,
V_54 , V_56 ) ;
return - V_46 ;
}
V_15 = F_10 ( V_2 , V_40 -> V_48 . V_26 ) ;
if ( V_15 ) {
F_9 ( & V_40 -> V_24 , L_9 ) ;
return - V_49 ;
}
return V_15 ;
}
static int F_24 ( struct V_57 * V_12 )
{
int V_15 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_51 * V_43 = NULL ;
struct V_39 * V_40 = NULL ;
struct V_58 V_48 ;
V_2 = F_25 ( & V_12 -> V_24 , sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_12 -> V_61 = 16 ;
V_15 = F_26 ( V_12 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_12 -> V_24 , L_10 ) ;
return V_15 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_24 = & V_12 -> V_24 ;
V_2 -> V_41 = F_27 ( & V_12 -> V_24 ) ;
if ( ! V_2 -> V_41 ) {
F_9 ( & V_12 -> V_24 , L_11 ) ;
return - V_46 ;
}
V_43 = F_28 ( & V_12 -> V_24 , L_12 , & V_12 -> V_24 , V_2 ,
& V_62 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
V_2 -> V_43 = V_43 ;
memset ( & V_48 , 0 , sizeof( struct V_58 ) ) ;
V_48 . type = V_63 ;
V_48 . V_55 = V_56 ;
V_40 = F_31 ( & V_12 -> V_24 , L_13 ,
& V_12 -> V_24 , V_2 ,
& V_64 , & V_48 ) ;
if ( F_29 ( V_40 ) )
return F_30 ( V_40 ) ;
V_40 -> V_48 . V_26 = V_65 ;
V_2 -> V_40 = V_40 ;
if ( ! V_2 -> V_41 -> V_66 ) {
V_2 -> V_35 = V_53 ;
F_18 ( V_2 , V_52 ) ;
} else {
V_2 -> V_35 = V_52 ;
}
F_32 ( V_12 , V_2 ) ;
F_33 ( & V_12 -> V_24 , L_14 ) ;
return 0 ;
}
static int F_34 ( struct V_57 * V_12 )
{
struct V_1 * V_2 = F_35 ( V_12 ) ;
F_18 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_36 ( struct V_67 * V_24 )
{
struct V_1 * V_2 = F_37 ( V_24 ) ;
F_38 ( V_24 , L_15 , V_2 -> V_35 ) ;
return F_18 ( V_2 , V_53 ) ;
}
static int F_39 ( struct V_67 * V_24 )
{
struct V_1 * V_2 = F_37 ( V_24 ) ;
V_2 -> V_35 = V_53 ;
return F_18 ( V_2 , V_52 ) ;
}
static void F_40 ( struct V_57 * V_12 )
{
struct V_1 * V_2 = F_35 ( V_12 ) ;
F_18 ( V_2 , V_53 ) ;
}
