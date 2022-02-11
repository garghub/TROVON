static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
const char V_5 [] = { V_6 ,
0 , 0 , 0 ,
0x02 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
F_2 ( V_2 , & V_4 ) ;
V_4 . V_7 = V_8 | V_9 ;
V_4 . V_10 = V_11 ;
V_4 . V_12 = V_13 ;
return F_3 ( V_2 , & V_4 , V_5 , V_14 , NULL , 0 , 0 ) ;
}
static enum V_15 F_4 ( struct V_1 * V_2 )
{
char V_16 [ 16 ] ;
unsigned int V_17 ;
struct V_18 * V_19 = ( void * ) ( V_16 + 8 ) ;
struct V_3 V_4 ;
char V_5 [] = { V_20 ,
2 ,
0 , 3 ,
0 , 0 , 0 ,
0 , sizeof( V_16 ) ,
0 , 0 , 0 ,
} ;
F_2 ( V_2 , & V_4 ) ;
V_4 . V_7 = V_8 | V_9 ;
V_4 . V_10 = V_11 ;
V_4 . V_12 = V_21 ;
V_4 . V_22 = sizeof( V_16 ) ;
V_17 = F_3 ( V_2 , & V_4 , V_5 , V_23 ,
V_16 , sizeof( V_16 ) , 0 ) ;
if ( V_17 )
return V_24 ;
if ( F_5 ( V_19 -> V_25 ) != 3 )
return V_24 ;
if ( V_19 -> V_26 == 0 && V_19 -> V_27 == 0 && V_19 -> V_28 == 1 )
return V_29 ;
else if ( V_19 -> V_26 == 1 && V_19 -> V_27 == 0 && V_19 -> V_28 == 1 )
return V_30 ;
else
return V_24 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
T_1 V_31 , * V_32 ;
unsigned int V_17 , V_33 , V_34 , V_35 ;
struct V_36 * V_36 = V_2 -> V_36 ;
V_17 = F_7 ( V_2 , & V_31 ) ;
if ( ! V_17 || V_31 != V_37 )
return false ;
V_32 = V_2 -> V_38 -> V_39 -> V_40 ;
V_17 = F_8 ( V_2 , V_32 , V_31 ) ;
if ( V_17 )
return false ;
if ( ( V_32 [ 0 ] & 0x7f ) != 0x70 )
return false ;
V_35 = V_32 [ 7 ] ;
if ( V_35 < 6 )
return false ;
V_33 = V_32 [ 12 ] ;
V_34 = V_32 [ 13 ] ;
if ( V_36 -> V_26 == V_29 )
return V_33 == 0x3a ;
else
return V_33 == 0x3a && V_34 == 0x01 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_36 * V_36 = V_2 -> V_36 ;
unsigned long V_41 ;
if ( ! F_6 ( V_2 ) ) {
V_36 -> V_42 = false ;
V_36 -> V_43 = false ;
return;
}
if ( ! V_36 -> V_42 ) {
V_36 -> V_42 = true ;
V_36 -> V_44 = V_45 ;
return;
}
V_41 = V_36 -> V_44 +
F_10 ( V_46 * 1000 ) ;
if ( F_11 ( V_45 , V_41 ) )
return;
V_36 -> V_43 = true ;
}
bool F_12 ( struct V_1 * V_2 )
{
struct V_36 * V_36 = V_2 -> V_36 ;
return V_36 -> V_43 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_36 * V_36 = V_2 -> V_36 ;
F_14 ( V_2 -> V_47 ) ;
V_36 -> V_48 = true ;
F_15 ( & V_2 -> V_49 , true ) ;
F_16 ( & V_2 -> V_49 , true ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_36 * V_36 = V_2 -> V_36 ;
if ( V_36 -> V_48 ) {
F_16 ( & V_2 -> V_49 , false ) ;
F_15 ( & V_2 -> V_49 , false ) ;
}
}
void F_18 ( struct V_1 * V_2 )
{
struct V_36 * V_36 = V_2 -> V_36 ;
if ( ! V_36 -> V_48 )
return;
V_36 -> V_48 = false ;
if ( V_36 -> V_50 ) {
V_36 -> V_50 = false ;
if ( V_36 -> V_26 == V_30 )
F_1 ( V_2 ) ;
}
V_36 -> V_42 = false ;
V_36 -> V_43 = false ;
F_19 ( V_2 -> V_47 ) ;
}
static void F_20 ( T_2 V_51 , T_3 V_52 , void * V_53 )
{
struct V_1 * V_54 = V_53 ;
struct V_36 * V_36 = V_54 -> V_36 ;
struct V_55 * V_2 = & V_54 -> V_47 -> V_56 ;
if ( V_52 == V_57 && F_21 ( V_2 ) ) {
V_36 -> V_50 = true ;
F_22 ( V_2 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
T_2 V_51 = F_24 ( V_2 ) ;
F_25 ( V_51 , V_58 ,
F_20 , V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_2 V_51 = F_24 ( V_2 ) ;
F_27 ( V_51 , V_58 , F_20 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_29 ( & V_2 -> V_49 ) ;
enum V_15 V_26 ;
struct V_36 * V_36 ;
if ( V_2 -> V_36 || ! V_60 || ! F_30 ( V_60 ) )
return;
V_26 = F_4 ( V_2 ) ;
if ( V_26 == V_24 )
return;
V_36 = F_31 ( sizeof( struct V_36 ) , V_61 ) ;
if ( ! V_36 )
return;
V_36 -> V_26 = V_26 ;
F_23 ( V_2 ) ;
V_36 -> V_2 = V_2 ;
V_2 -> V_36 = V_36 ;
F_32 ( & V_2 -> V_49 , 0 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_34 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
