void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_4 -> V_8 [ V_5 ] = 0 ;
V_4 -> V_9 [ V_5 ] = 0 ;
}
V_4 -> V_10 = 1 << V_2 -> V_11 . V_12 ;
V_4 -> V_13 = 0 ;
}
void F_3 ( struct V_1 * V_2 , struct V_14 * V_4 )
{
int V_5 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 -> V_8 [ V_5 ] = 0 ;
V_4 -> V_9 [ V_5 ] = 0 ;
}
V_4 -> V_10 = ( 1 << V_2 -> V_11 . V_16 ) - V_17 ;
V_4 -> V_13 = 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_18 ,
T_2 * V_8 )
{
struct V_19 * V_20 ;
T_3 V_21 ;
int V_22 ;
V_20 = F_5 ( V_2 ) ;
if ( F_6 ( V_20 ) )
return F_7 ( V_20 ) ;
memcpy ( V_20 -> V_23 , V_8 , V_24 ) ;
V_21 = V_25 << 8 | V_18 ;
V_22 = F_8 ( V_2 , V_20 -> V_26 , V_21 , 1 , V_27 ,
V_28 ) ;
F_9 ( V_2 , V_20 ) ;
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_18 ,
T_4 V_29 , int * V_30 , T_1 V_31 )
{
struct V_32 V_33 ;
T_1 V_34 [ 16 ] = { 0 } ;
int V_22 ;
if ( V_31 ) {
V_22 = F_11 ( V_2 , 1 , 1 , V_30 ) ;
if ( V_22 ) {
F_12 ( V_2 , L_1 ) ;
return V_22 ;
}
}
V_33 . V_30 = * V_30 ;
V_29 &= 0xffffffffffffULL ;
V_29 = F_13 ( V_29 << 16 ) ;
memcpy ( & V_34 [ 10 ] , & V_29 , V_35 ) ;
V_34 [ 5 ] = V_18 ;
V_34 [ 7 ] = V_36 << 1 ;
V_22 = F_14 ( V_2 , & V_33 , V_34 , 0 ,
V_37 , V_36 ) ;
if ( V_22 && V_31 )
F_15 ( V_2 , * V_30 , 1 ) ;
return V_22 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_18 ,
T_4 V_29 , int V_30 , T_1 free )
{
struct V_32 V_33 ;
T_1 V_34 [ 16 ] = { 0 } ;
V_33 . V_30 = V_30 ;
V_29 &= 0xffffffffffffULL ;
V_29 = F_13 ( V_29 << 16 ) ;
memcpy ( & V_34 [ 10 ] , & V_29 , V_35 ) ;
V_34 [ 5 ] = V_18 ;
V_34 [ 7 ] = V_36 << 1 ;
F_17 ( V_2 , & V_33 , V_34 , V_37 , V_36 ) ;
if ( free )
F_15 ( V_2 , V_30 , 1 ) ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_18 , T_4 V_29 , int * V_30 , T_1 V_38 )
{
struct V_39 * V_40 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_40 -> V_41 ;
struct V_42 * V_43 ;
int V_5 , V_22 = 0 ;
int free = - 1 ;
if ( V_2 -> V_11 . V_44 & V_45 ) {
V_22 = F_10 ( V_2 , V_18 , V_29 , V_30 , 1 ) ;
if ( V_22 )
return V_22 ;
V_43 = F_20 ( sizeof *V_43 , V_46 ) ;
if ( ! V_43 ) {
F_16 ( V_2 , V_18 , V_29 , * V_30 , 1 ) ;
return - V_47 ;
}
V_43 -> V_29 = V_29 ;
V_22 = F_21 ( & V_40 -> V_48 , * V_30 , V_43 ) ;
if ( V_22 ) {
F_22 ( V_43 ) ;
F_16 ( V_2 , V_18 , V_29 , * V_30 , 1 ) ;
return V_22 ;
}
}
F_23 ( V_2 , L_2 , ( unsigned long long ) V_29 ) ;
F_24 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 - 1 ; V_5 ++ ) {
if ( free < 0 && ! V_4 -> V_9 [ V_5 ] ) {
free = V_5 ;
continue;
}
if ( V_29 == ( V_49 & F_25 ( V_4 -> V_8 [ V_5 ] ) ) ) {
++ V_4 -> V_9 [ V_5 ] ;
goto V_50;
}
}
if ( free < 0 ) {
V_22 = - V_47 ;
goto V_50;
}
F_23 ( V_2 , L_3 , free ) ;
if ( V_4 -> V_13 == V_4 -> V_10 ) {
V_22 = - V_51 ;
goto V_50;
}
V_4 -> V_9 [ free ] = 1 ;
V_4 -> V_8 [ free ] = F_13 ( V_29 | V_52 ) ;
V_22 = F_4 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_26 ( V_22 ) ) {
F_12 ( V_2 , L_4 , ( unsigned long long ) V_29 ) ;
V_4 -> V_9 [ free ] = 0 ;
V_4 -> V_8 [ free ] = 0 ;
goto V_50;
}
if ( ! ( V_2 -> V_11 . V_44 & V_45 ) )
* V_30 = V_40 -> V_53 + free ;
++ V_4 -> V_13 ;
V_50:
F_27 ( & V_4 -> V_6 ) ;
return V_22 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_54 )
{
int V_22 = 0 ;
if ( V_54 < 0 || V_54 >= V_4 -> V_10 || ! V_4 -> V_8 [ V_54 ] ) {
F_29 ( V_2 , L_5 ) ;
V_22 = - V_55 ;
}
return V_22 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_29 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( V_29 == ( V_49 & F_25 ( V_4 -> V_8 [ V_5 ] ) ) )
return V_5 ;
}
return - V_55 ;
}
void F_31 ( struct V_1 * V_2 , T_1 V_18 , int V_30 )
{
struct V_39 * V_40 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_40 -> V_41 ;
int V_54 = V_30 - V_40 -> V_53 ;
struct V_42 * V_43 ;
if ( V_2 -> V_11 . V_44 & V_45 ) {
V_43 = F_32 ( & V_40 -> V_48 , V_30 ) ;
if ( V_43 ) {
F_16 ( V_2 , V_18 , V_43 -> V_29 , V_30 , 1 ) ;
F_33 ( & V_40 -> V_48 , V_30 ) ;
V_54 = F_30 ( V_2 , V_4 , V_43 -> V_29 ) ;
F_22 ( V_43 ) ;
}
}
F_24 ( & V_4 -> V_6 ) ;
if ( F_28 ( V_2 , V_4 , V_54 ) )
goto V_50;
if ( ! ( -- V_4 -> V_9 [ V_54 ] ) ) {
V_4 -> V_8 [ V_54 ] = 0 ;
F_4 ( V_2 , V_18 , V_4 -> V_8 ) ;
-- V_4 -> V_13 ;
}
V_50:
F_27 ( & V_4 -> V_6 ) ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_18 , int V_30 , T_4 V_56 , T_1 V_38 )
{
struct V_39 * V_40 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_40 -> V_41 ;
int V_54 = V_30 - V_40 -> V_53 ;
struct V_42 * V_43 ;
int V_22 ;
if ( V_2 -> V_11 . V_44 & V_45 ) {
V_43 = F_32 ( & V_40 -> V_48 , V_30 ) ;
if ( ! V_43 )
return - V_55 ;
V_54 = F_30 ( V_2 , V_4 , V_43 -> V_29 ) ;
F_16 ( V_2 , V_18 , V_43 -> V_29 , V_30 , 0 ) ;
V_43 -> V_29 = V_56 ;
V_22 = F_10 ( V_2 , V_18 , V_43 -> V_29 , & V_30 , 0 ) ;
if ( V_22 || V_54 < 0 )
return V_22 ;
}
F_24 ( & V_4 -> V_6 ) ;
V_22 = F_28 ( V_2 , V_4 , V_54 ) ;
if ( V_22 )
goto V_50;
V_4 -> V_8 [ V_54 ] = F_13 ( V_56 | V_52 ) ;
V_22 = F_4 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_26 ( V_22 ) ) {
F_12 ( V_2 , L_4 , ( unsigned long long ) V_56 ) ;
V_4 -> V_8 [ V_54 ] = 0 ;
}
V_50:
F_27 ( & V_4 -> V_6 ) ;
return V_22 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_18 ,
T_5 * V_8 )
{
struct V_19 * V_20 ;
T_3 V_21 ;
int V_22 ;
V_20 = F_5 ( V_2 ) ;
if ( F_6 ( V_20 ) )
return F_7 ( V_20 ) ;
memcpy ( V_20 -> V_23 , V_8 , V_57 ) ;
V_21 = V_58 << 8 | V_18 ;
V_22 = F_8 ( V_2 , V_20 -> V_26 , V_21 , 1 , V_27 ,
V_28 ) ;
F_9 ( V_2 , V_20 ) ;
return V_22 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_59 , int * V_60 )
{
struct V_14 * V_4 = & F_19 ( V_2 ) -> V_18 [ V_18 ] . V_61 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_15 ; ++ V_5 ) {
if ( V_4 -> V_9 [ V_5 ] &&
( V_59 == ( V_62 &
F_37 ( V_4 -> V_8 [ V_5 ] ) ) ) ) {
* V_60 = V_5 ;
return 0 ;
}
}
return - V_63 ;
}
int F_38 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_64 , int * V_54 )
{
struct V_14 * V_4 = & F_19 ( V_2 ) -> V_18 [ V_18 ] . V_61 ;
int V_5 , V_22 = 0 ;
int free = - 1 ;
F_24 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_13 == V_4 -> V_10 ) {
V_22 = - V_51 ;
goto V_50;
}
for ( V_5 = V_17 ; V_5 < V_15 ; V_5 ++ ) {
if ( free < 0 && ( V_4 -> V_9 [ V_5 ] == 0 ) ) {
free = V_5 ;
continue;
}
if ( V_4 -> V_9 [ V_5 ] &&
( V_64 == ( V_62 &
F_37 ( V_4 -> V_8 [ V_5 ] ) ) ) ) {
* V_54 = V_5 ;
++ V_4 -> V_9 [ V_5 ] ;
goto V_50;
}
}
if ( free < 0 ) {
V_22 = - V_47 ;
goto V_50;
}
V_4 -> V_9 [ free ] = 1 ;
V_4 -> V_8 [ free ] = F_39 ( V_64 | V_65 ) ;
V_22 = F_35 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_26 ( V_22 ) ) {
F_29 ( V_2 , L_6 , V_64 ) ;
V_4 -> V_9 [ free ] = 0 ;
V_4 -> V_8 [ free ] = 0 ;
goto V_50;
}
* V_54 = free ;
++ V_4 -> V_13 ;
V_50:
F_27 ( & V_4 -> V_6 ) ;
return V_22 ;
}
void F_40 ( struct V_1 * V_2 , T_1 V_18 , int V_54 )
{
struct V_14 * V_4 = & F_19 ( V_2 ) -> V_18 [ V_18 ] . V_61 ;
if ( V_54 < V_17 ) {
F_29 ( V_2 , L_7 , V_54 ) ;
return;
}
F_24 ( & V_4 -> V_6 ) ;
if ( ! V_4 -> V_9 [ V_54 ] ) {
F_29 ( V_2 , L_8 , V_54 ) ;
goto V_50;
}
if ( -- V_4 -> V_9 [ V_54 ] ) {
F_23 ( V_2 , L_9
L_10 , V_54 ) ;
goto V_50;
}
V_4 -> V_8 [ V_54 ] = 0 ;
F_35 ( V_2 , V_18 , V_4 -> V_8 ) ;
-- V_4 -> V_13 ;
V_50:
F_27 ( & V_4 -> V_6 ) ;
}
int F_41 ( struct V_1 * V_2 , T_1 V_18 , T_5 * V_11 )
{
struct V_19 * V_66 , * V_67 ;
T_1 * V_68 , * V_69 ;
int V_22 ;
V_66 = F_5 ( V_2 ) ;
if ( F_6 ( V_66 ) )
return F_7 ( V_66 ) ;
V_67 = F_5 ( V_2 ) ;
if ( F_6 ( V_67 ) ) {
F_9 ( V_2 , V_66 ) ;
return F_7 ( V_67 ) ;
}
V_68 = V_66 -> V_23 ;
V_69 = V_67 -> V_23 ;
memset ( V_68 , 0 , 256 ) ;
memset ( V_69 , 0 , 256 ) ;
V_68 [ 0 ] = 1 ;
V_68 [ 1 ] = 1 ;
V_68 [ 2 ] = 1 ;
V_68 [ 3 ] = 1 ;
* ( V_70 * ) ( & V_68 [ 16 ] ) = F_42 ( 0x0015 ) ;
* ( T_5 * ) ( & V_68 [ 20 ] ) = F_39 ( V_18 ) ;
V_22 = F_43 ( V_2 , V_66 -> V_26 , V_67 -> V_26 , V_18 , 3 ,
V_71 , V_72 ) ;
if ( ! V_22 )
* V_11 = * ( T_5 * ) ( V_69 + 84 ) ;
F_9 ( V_2 , V_66 ) ;
F_9 ( V_2 , V_67 ) ;
return V_22 ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_19 * V_66 , * V_67 ;
T_1 * V_68 , * V_69 ;
int V_22 , V_73 ;
V_66 = F_5 ( V_2 ) ;
if ( F_6 ( V_66 ) )
return F_7 ( V_66 ) ;
V_67 = F_5 ( V_2 ) ;
if ( F_6 ( V_67 ) ) {
F_9 ( V_2 , V_66 ) ;
return F_7 ( V_67 ) ;
}
V_68 = V_66 -> V_23 ;
V_69 = V_67 -> V_23 ;
memset ( V_68 , 0 , 256 ) ;
memset ( V_69 , 0 , 256 ) ;
V_68 [ 0 ] = 1 ;
V_68 [ 1 ] = 1 ;
V_68 [ 2 ] = 1 ;
V_68 [ 3 ] = 1 ;
* ( V_70 * ) ( & V_68 [ 16 ] ) = V_74 ;
* ( T_5 * ) ( & V_68 [ 20 ] ) = F_39 ( V_18 ) ;
V_22 = F_43 ( V_2 , V_66 -> V_26 , V_67 -> V_26 , V_18 , 3 ,
V_71 , V_72 ) ;
V_73 = F_45 ( * ( V_70 * ) ( V_69 + 4 ) ) ;
V_2 -> V_11 . V_75 [ V_18 ] = ( ! V_22 && ! V_73 ) ?
V_76
: 0 ;
F_9 ( V_2 , V_66 ) ;
F_9 ( V_2 , V_67 ) ;
return V_22 ;
}
int F_46 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_19 * V_20 ;
int V_22 ;
if ( V_2 -> V_11 . V_77 [ V_18 ] == V_78 )
return 0 ;
V_20 = F_5 ( V_2 ) ;
if ( F_6 ( V_20 ) )
return F_7 ( V_20 ) ;
memset ( V_20 -> V_23 , 0 , 256 ) ;
( ( T_5 * ) V_20 -> V_23 ) [ 1 ] = V_2 -> V_11 . V_79 [ V_18 ] ;
V_22 = F_8 ( V_2 , V_20 -> V_26 , V_18 , 0 , V_27 ,
V_28 ) ;
F_9 ( V_2 , V_20 ) ;
return V_22 ;
}
