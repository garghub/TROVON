static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_6 ,
& V_3 , sizeof( V_3 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_3 ( & V_2 -> V_7 ) )
F_4 ( & V_2 -> V_7 ) ;
V_5 = F_5 ( V_2 , V_6 ,
& V_3 , sizeof( V_3 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_6 ( & V_2 -> V_7 ,
F_7 ( V_8 ) ) == 0 ) {
V_5 = F_2 ( V_2 , V_9 ,
& V_4 , sizeof( V_4 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! ( F_8 ( V_4 ) & V_10 ) )
return - V_11 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_12 * V_14 )
{
T_1 V_3 [ 2 ] ;
int V_5 ;
V_5 = F_10 ( V_2 , V_15 , V_3 , sizeof( V_3 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_13 -> V_16 =
F_11 (unsigned int, be32_to_cpu(reg[0]), MAX_STREAMS) ;
V_13 -> V_17 = F_8 ( V_3 [ 1 ] ) * 4 ;
V_5 = F_12 ( V_2 , V_18 , V_3 , sizeof( V_3 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_14 -> V_16 =
F_11 (unsigned int, be32_to_cpu(reg[0]), MAX_STREAMS) ;
V_14 -> V_17 = F_8 ( V_3 [ 1 ] ) * 4 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( F_14 ( & V_2 -> V_21 [ V_19 ] ) ) {
F_15 ( & V_2 -> V_21 [ V_19 ] ) ;
F_16 ( & V_2 -> V_21 [ V_19 ] ) ;
}
if ( F_14 ( & V_2 -> V_22 [ V_19 ] ) ) {
F_15 ( & V_2 -> V_22 [ V_19 ] ) ;
F_16 ( & V_2 -> V_22 [ V_19 ] ) ;
}
F_17 ( & V_2 -> V_23 [ V_19 ] ) ;
F_17 ( & V_2 -> V_24 [ V_19 ] ) ;
}
}
static void F_18 ( struct V_1 * V_2 , enum V_25 V_26 ,
struct V_12 * V_27 )
{
T_1 V_3 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_27 -> V_16 ; V_19 ++ ) {
V_3 = F_19 ( ( V_28 ) - 1 ) ;
if ( V_26 == V_29 ) {
F_20 ( V_2 ,
V_27 -> V_17 * V_19 + V_30 ,
& V_3 , sizeof( V_3 ) ) ;
} else {
F_21 ( V_2 ,
V_27 -> V_17 * V_19 + V_31 ,
& V_3 , sizeof( V_3 ) ) ;
}
}
}
static int F_22 ( struct V_1 * V_2 ,
enum V_25 V_26 , unsigned int V_32 ,
unsigned int V_33 , unsigned int V_34 ,
unsigned int V_35 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
bool V_40 ;
unsigned int V_19 ;
int V_5 ;
if ( V_26 == V_29 ) {
V_37 = & V_2 -> V_21 [ V_32 ] ;
V_39 = & V_2 -> V_23 [ V_32 ] ;
} else {
V_37 = & V_2 -> V_22 [ V_32 ] ;
V_39 = & V_2 -> V_24 [ V_32 ] ;
}
V_40 = V_33 > 96000 ;
if ( V_40 ) {
V_33 /= 2 ;
V_34 *= 2 ;
}
V_5 = F_23 ( V_37 , V_33 , V_34 , V_35 ,
V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_40 ) {
V_34 /= 2 ;
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
F_24 ( V_37 , V_19 , V_19 * 2 ) ;
F_24 ( V_37 , V_19 + V_34 ,
V_19 * 2 + 1 ) ;
}
}
return F_25 ( V_39 ,
F_26 ( V_37 ) ,
F_27 ( V_2 -> V_41 ) -> V_42 ) ;
}
static int F_28 ( struct V_1 * V_2 , enum V_25 V_26 ,
unsigned int V_33 , struct V_12 * V_27 )
{
T_1 V_3 [ 2 ] ;
unsigned int V_19 , V_34 , V_35 ;
struct V_36 * V_43 ;
struct V_38 * V_39 ;
int V_5 = 0 ;
if ( V_26 == V_29 ) {
V_43 = V_2 -> V_21 ;
V_39 = V_2 -> V_23 ;
} else {
V_43 = V_2 -> V_22 ;
V_39 = V_2 -> V_24 ;
}
for ( V_19 = 0 ; V_19 < V_27 -> V_16 ; V_19 ++ ) {
if ( V_26 == V_29 ) {
V_5 = F_10 ( V_2 ,
V_27 -> V_17 * V_19 + V_44 ,
V_3 , sizeof( V_3 ) ) ;
} else {
V_5 = F_12 ( V_2 ,
V_27 -> V_17 * V_19 + V_45 ,
V_3 , sizeof( V_3 ) ) ;
}
if ( V_5 < 0 )
return V_5 ;
V_34 = F_8 ( V_3 [ 0 ] ) ;
V_35 = F_8 ( V_3 [ 1 ] ) ;
V_5 = F_22 ( V_2 , V_26 , V_19 , V_33 , V_34 , V_35 ) ;
if ( V_5 < 0 )
return V_5 ;
V_3 [ 0 ] = F_19 ( V_39 [ V_19 ] . V_46 ) ;
if ( V_26 == V_29 ) {
V_5 = F_20 ( V_2 ,
V_27 -> V_17 * V_19 + V_30 ,
V_3 , sizeof( V_3 [ 0 ] ) ) ;
} else {
V_5 = F_21 ( V_2 ,
V_27 -> V_17 * V_19 + V_31 ,
V_3 , sizeof( V_3 [ 0 ] ) ) ;
}
if ( V_5 < 0 )
return V_5 ;
V_5 = F_29 ( & V_43 [ V_19 ] , V_39 [ V_19 ] . V_46 ,
F_27 ( V_2 -> V_41 ) -> V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return V_5 ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_33 )
{
unsigned int V_47 ;
unsigned int V_19 ;
struct V_12 V_13 , V_14 ;
bool V_48 ;
int V_5 ;
if ( V_2 -> V_49 == 0 )
return - V_50 ;
V_5 = F_9 ( V_2 , & V_13 , & V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_31 ( V_2 , & V_47 ) ;
if ( V_5 < 0 ) {
F_32 ( & V_2 -> V_41 -> V_51 ,
L_1 ) ;
return V_5 ;
}
if ( V_33 == 0 )
V_33 = V_47 ;
if ( V_33 != V_47 )
return - V_52 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( V_19 < V_13 . V_16 ) {
if ( F_33 ( & V_2 -> V_21 [ V_19 ] ) ||
! F_14 ( & V_2 -> V_21 [ V_19 ] ) )
break;
}
if ( V_19 < V_14 . V_16 ) {
if ( F_33 ( & V_2 -> V_22 [ V_19 ] ) ||
! F_14 ( & V_2 -> V_22 [ V_19 ] ) )
break;
}
}
V_48 = ( V_19 < V_20 ) ;
if ( V_48 ) {
F_34 ( V_2 ) ;
F_18 ( V_2 , V_29 , & V_13 ) ;
F_18 ( V_2 , V_53 , & V_14 ) ;
F_13 ( V_2 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 ) {
F_32 ( & V_2 -> V_41 -> V_51 ,
L_2 ) ;
return V_5 ;
}
V_5 = F_28 ( V_2 , V_29 , V_33 , & V_13 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_28 ( V_2 , V_53 , V_33 , & V_14 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_35 ( V_2 ) ;
if ( V_5 < 0 ) {
F_32 ( & V_2 -> V_41 -> V_51 ,
L_3 ) ;
goto error;
}
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( ( V_19 < V_13 . V_16 &&
! F_36 ( & V_2 -> V_21 [ V_19 ] ,
V_54 ) ) ||
( V_19 < V_14 . V_16 &&
! F_36 ( & V_2 -> V_22 [ V_19 ] ,
V_54 ) ) ) {
V_5 = - V_11 ;
goto error;
}
}
}
return V_5 ;
error:
F_34 ( V_2 ) ;
F_18 ( V_2 , V_29 , & V_13 ) ;
F_18 ( V_2 , V_53 , & V_14 ) ;
F_13 ( V_2 ) ;
return V_5 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_12 V_13 , V_14 ;
if ( V_2 -> V_49 > 0 )
return;
F_34 ( V_2 ) ;
if ( F_9 ( V_2 , & V_13 , & V_14 ) == 0 ) {
F_18 ( V_2 , V_29 , & V_13 ) ;
F_18 ( V_2 , V_53 , & V_14 ) ;
}
F_13 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , enum V_25 V_26 ,
unsigned int V_32 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_5 ;
if ( V_26 == V_29 ) {
V_37 = & V_2 -> V_21 [ V_32 ] ;
V_39 = & V_2 -> V_23 [ V_32 ] ;
} else {
V_37 = & V_2 -> V_22 [ V_32 ] ;
V_39 = & V_2 -> V_24 [ V_32 ] ;
}
V_5 = F_39 ( V_39 , V_2 -> V_41 ) ;
if ( V_5 < 0 )
goto V_55;
V_39 -> V_56 = 0x00000000ffffffffuLL ;
V_5 = F_40 ( V_37 , V_2 -> V_41 , V_26 , V_57 ) ;
if ( V_5 < 0 ) {
F_41 ( V_37 ) ;
F_42 ( V_39 ) ;
}
V_55:
return V_5 ;
}
static void F_43 ( struct V_1 * V_2 ,
enum V_25 V_26 ,
unsigned int V_32 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
if ( V_26 == V_29 ) {
V_37 = & V_2 -> V_21 [ V_32 ] ;
V_39 = & V_2 -> V_23 [ V_32 ] ;
} else {
V_37 = & V_2 -> V_22 [ V_32 ] ;
V_39 = & V_2 -> V_24 [ V_32 ] ;
}
F_41 ( V_37 ) ;
F_42 ( V_39 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_19 , V_5 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_5 = F_38 ( V_2 , V_29 , V_19 ) ;
if ( V_5 < 0 ) {
for (; V_19 >= 0 ; V_19 -- )
F_43 ( V_2 , V_53 , V_19 ) ;
goto V_55;
}
}
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_5 = F_38 ( V_2 , V_53 , V_19 ) ;
if ( V_5 < 0 ) {
for (; V_19 >= 0 ; V_19 -- )
F_43 ( V_2 , V_53 , V_19 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
F_43 ( V_2 , V_29 , V_19 ) ;
break;
}
}
V_55:
return V_5 ;
}
void F_45 ( struct V_1 * V_2 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
F_43 ( V_2 , V_29 , V_19 ) ;
F_43 ( V_2 , V_53 , V_19 ) ;
}
}
void F_46 ( struct V_1 * V_2 )
{
struct V_12 V_13 , V_14 ;
V_2 -> V_58 = false ;
if ( F_9 ( V_2 , & V_13 , & V_14 ) == 0 ) {
F_18 ( V_2 , V_29 , & V_13 ) ;
F_18 ( V_2 , V_53 , & V_14 ) ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_59 = true ;
F_48 ( & V_2 -> V_60 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
int V_5 ;
F_50 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 < 0 ) {
V_5 = - V_63 ;
goto V_64;
}
if ( V_2 -> V_62 ++ == 0 )
F_47 ( V_2 ) ;
V_5 = 0 ;
V_64:
F_51 ( & V_2 -> V_61 ) ;
return V_5 ;
}
void F_52 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_61 ) ;
if ( F_53 ( V_2 -> V_62 <= 0 ) )
goto V_64;
if ( -- V_2 -> V_62 == 0 )
F_47 ( V_2 ) ;
V_64:
F_51 ( & V_2 -> V_61 ) ;
}
