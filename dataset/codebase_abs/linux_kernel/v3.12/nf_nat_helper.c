static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
const char * V_6 ,
unsigned int V_7 )
{
unsigned char * V_8 ;
F_2 ( F_3 ( V_2 ) ) ;
V_8 = F_4 ( V_2 ) + V_3 ;
memmove ( V_8 + V_4 + V_7 ,
V_8 + V_4 + V_5 ,
F_5 ( V_2 ) - ( F_4 ( V_2 ) + V_3 +
V_4 + V_5 ) ) ;
memcpy ( V_8 + V_4 , V_6 , V_7 ) ;
if ( V_7 > V_5 ) {
F_6 ( L_1
L_2 , V_7 - V_5 , V_2 -> V_9 ) ;
F_7 ( V_2 , V_7 - V_5 ) ;
} else {
F_6 ( L_3
L_2 , V_5 - V_7 , V_2 -> V_9 ) ;
F_8 ( V_2 , V_2 -> V_9 + V_7 - V_5 ) ;
}
if ( F_9 ( (struct V_10 * ) V_2 -> V_11 ) == V_12 ) {
F_10 ( V_2 ) -> V_13 = F_11 ( V_2 -> V_9 ) ;
F_12 ( F_10 ( V_2 ) ) ;
} else
F_13 ( V_2 ) -> V_14 =
F_11 ( V_2 -> V_9 - sizeof( struct V_15 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_16 )
{
if ( V_2 -> V_9 + V_16 > 65535 )
return 0 ;
if ( F_15 ( V_2 , 0 , V_16 - F_16 ( V_2 ) , V_17 ) )
return 0 ;
return 1 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_10 * V_18 ,
enum V_19 V_20 ,
unsigned int V_21 ,
unsigned int V_4 ,
unsigned int V_5 ,
const char * V_6 ,
unsigned int V_7 , bool V_22 )
{
const struct V_23 * V_24 ;
struct V_25 * V_26 ;
int V_27 , V_28 ;
if ( ! F_18 ( V_2 , V_2 -> V_9 ) )
return 0 ;
if ( V_7 > V_5 &&
V_7 - V_5 > F_16 ( V_2 ) &&
! F_14 ( V_2 , V_7 - V_5 ) )
return 0 ;
F_19 ( V_2 ) ;
V_26 = ( void * ) V_2 -> V_8 + V_21 ;
V_27 = V_2 -> V_9 - V_21 ;
F_1 ( V_2 , V_21 + V_26 -> V_29 * 4 ,
V_4 , V_5 , V_6 , V_7 ) ;
V_28 = V_2 -> V_9 - V_21 ;
V_24 = F_20 ( F_9 ( V_18 ) ) ;
V_24 -> V_30 ( V_2 , V_31 , V_26 , & V_26 -> V_32 ,
V_28 , V_27 ) ;
if ( V_22 && V_7 != V_5 )
F_21 ( V_18 , V_20 , V_26 -> V_33 ,
( int ) V_7 - ( int ) V_5 ) ;
return 1 ;
}
int
F_22 ( struct V_1 * V_2 ,
struct V_10 * V_18 ,
enum V_19 V_20 ,
unsigned int V_21 ,
unsigned int V_4 ,
unsigned int V_5 ,
const char * V_6 ,
unsigned int V_7 )
{
const struct V_23 * V_24 ;
struct V_34 * V_35 ;
int V_28 , V_27 ;
if ( ! F_18 ( V_2 , V_2 -> V_9 ) )
return 0 ;
if ( V_7 > V_5 &&
V_7 - V_5 > F_16 ( V_2 ) &&
! F_14 ( V_2 , V_7 - V_5 ) )
return 0 ;
V_35 = ( void * ) V_2 -> V_8 + V_21 ;
V_27 = V_2 -> V_9 - V_21 ;
F_1 ( V_2 , V_21 + sizeof( * V_35 ) ,
V_4 , V_5 , V_6 , V_7 ) ;
V_28 = V_2 -> V_9 - V_21 ;
V_35 -> V_9 = F_11 ( V_28 ) ;
if ( ! V_35 -> V_32 && V_2 -> V_36 != V_37 )
return 1 ;
V_24 = F_20 ( F_9 ( V_18 ) ) ;
V_24 -> V_30 ( V_2 , V_38 , V_35 , & V_35 -> V_32 ,
V_28 , V_27 ) ;
return 1 ;
}
void F_23 ( struct V_10 * V_18 ,
struct V_39 * exp )
{
struct V_40 V_41 ;
F_2 ( V_18 -> V_42 & V_43 ) ;
V_41 . V_44 = V_45 ;
V_41 . V_46 = V_41 . V_47
= V_18 -> V_48 -> V_49 [ ! exp -> V_50 ] . V_51 . V_52 . V_53 ;
F_24 ( V_18 , & V_41 , V_54 ) ;
V_41 . V_44 = ( V_45 | V_55 ) ;
V_41 . V_56 = V_41 . V_57 = exp -> V_58 ;
V_41 . V_46 = V_41 . V_47
= V_18 -> V_48 -> V_49 [ ! exp -> V_50 ] . V_51 . V_59 . V_53 ;
F_24 ( V_18 , & V_41 , V_60 ) ;
}
