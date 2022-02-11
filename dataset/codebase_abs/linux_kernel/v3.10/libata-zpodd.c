static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {} ;
const char V_5 [] = { V_6 ,
0 , 0 , 0 ,
0x02 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
V_4 . V_7 = V_8 | V_9 ;
V_4 . V_10 = V_11 ;
V_4 . V_12 = V_13 ;
return F_2 ( V_2 , & V_4 , V_5 , V_14 , NULL , 0 , 0 ) ;
}
static enum V_15 F_3 ( struct V_1 * V_2 )
{
char V_16 [ 16 ] ;
unsigned int V_17 ;
struct V_18 * V_19 = ( void * ) ( V_16 + 8 ) ;
struct V_3 V_4 = {} ;
char V_5 [] = { V_20 ,
2 ,
0 , 3 ,
0 , 0 , 0 ,
0 , sizeof( V_16 ) ,
0 , 0 , 0 ,
} ;
V_4 . V_7 = V_8 | V_9 ;
V_4 . V_10 = V_11 ;
V_4 . V_12 = V_21 ;
V_4 . V_22 = sizeof( V_16 ) ;
V_17 = F_2 ( V_2 , & V_4 , V_5 , V_23 ,
V_16 , sizeof( V_16 ) , 0 ) ;
if ( V_17 )
return V_24 ;
if ( F_4 ( V_19 -> V_25 ) != 3 )
return V_24 ;
if ( V_19 -> V_26 == 0 && V_19 -> V_27 == 0 && V_19 -> V_28 == 1 )
return V_29 ;
else if ( V_19 -> V_26 == 1 && V_19 -> V_27 == 0 && V_19 -> V_28 == 1 )
return V_30 ;
else
return V_24 ;
}
static bool F_5 ( struct V_1 * V_31 )
{
T_1 V_32 ;
T_2 V_33 ;
struct V_34 * V_35 ;
V_32 = F_6 ( V_31 ) ;
if ( ! V_32 )
return false ;
V_33 = F_7 ( V_32 , & V_35 ) ;
if ( F_8 ( V_33 ) )
return false ;
return F_9 ( V_35 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
T_3 V_36 , * V_37 ;
unsigned int V_17 , V_38 , V_39 , V_40 ;
struct V_41 * V_41 = V_2 -> V_41 ;
V_17 = F_11 ( V_2 , & V_36 ) ;
if ( ! V_17 || V_36 != V_42 )
return false ;
V_37 = V_2 -> V_43 -> V_44 -> V_45 ;
V_17 = F_12 ( V_2 , V_37 , V_36 ) ;
if ( V_17 )
return false ;
if ( ( V_37 [ 0 ] & 0x7f ) != 0x70 )
return false ;
V_40 = V_37 [ 7 ] ;
if ( V_40 < 6 )
return false ;
V_38 = V_37 [ 12 ] ;
V_39 = V_37 [ 13 ] ;
if ( V_41 -> V_26 == V_29 )
return V_38 == 0x3a ;
else
return V_38 == 0x3a && V_39 == 0x01 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
unsigned long V_46 ;
if ( ! F_10 ( V_2 ) ) {
V_41 -> V_47 = false ;
V_41 -> V_48 = false ;
return;
}
if ( ! V_41 -> V_47 ) {
V_41 -> V_47 = true ;
V_41 -> V_49 = V_50 ;
return;
}
V_46 = V_41 -> V_49 +
F_14 ( V_51 * 1000 ) ;
if ( F_15 ( V_50 , V_46 ) )
return;
V_41 -> V_48 = true ;
}
bool F_16 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
return V_41 -> V_48 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
F_18 ( V_2 -> V_52 ) ;
V_41 -> V_53 = true ;
F_19 ( & V_2 -> V_52 -> V_54 , true ) ;
F_20 ( & V_2 -> V_52 -> V_54 , true ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
if ( V_41 -> V_53 ) {
F_20 ( & V_2 -> V_52 -> V_54 , false ) ;
F_19 ( & V_2 -> V_52 -> V_54 , false ) ;
}
}
void F_22 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
if ( ! V_41 -> V_53 )
return;
V_41 -> V_53 = false ;
if ( V_41 -> V_55 ) {
V_41 -> V_55 = false ;
if ( V_41 -> V_26 == V_30 )
F_1 ( V_2 ) ;
}
V_41 -> V_47 = false ;
V_41 -> V_48 = false ;
F_23 ( V_2 -> V_52 ) ;
}
static void F_24 ( T_1 V_32 , T_4 V_56 , void * V_57 )
{
struct V_1 * V_31 = V_57 ;
struct V_41 * V_41 = V_31 -> V_41 ;
struct V_58 * V_2 = & V_31 -> V_52 -> V_54 ;
if ( V_56 == V_59 && F_25 ( V_2 ) ) {
V_41 -> V_55 = true ;
F_26 ( V_2 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_32 = F_6 ( V_2 ) ;
F_28 ( V_32 , V_60 ,
F_24 , V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_32 = F_30 ( & V_2 -> V_52 -> V_54 ) ;
F_31 ( V_32 , V_60 , F_24 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
enum V_15 V_26 ;
struct V_41 * V_41 ;
if ( V_2 -> V_41 )
return;
if ( ! F_5 ( V_2 ) )
return;
V_26 = F_3 ( V_2 ) ;
if ( V_26 == V_24 )
return;
V_41 = F_33 ( sizeof( struct V_41 ) , V_61 ) ;
if ( ! V_41 )
return;
V_41 -> V_26 = V_26 ;
F_27 ( V_2 ) ;
V_41 -> V_2 = V_2 ;
V_2 -> V_41 = V_41 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_35 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
