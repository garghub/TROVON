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
if ( F_9 ( (struct V_10 * ) F_10 ( V_2 ) ) == V_11 ) {
F_11 ( V_2 ) -> V_12 = F_12 ( V_2 -> V_9 ) ;
F_13 ( F_11 ( V_2 ) ) ;
} else
F_14 ( V_2 ) -> V_13 =
F_12 ( V_2 -> V_9 - sizeof( struct V_14 ) ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_15 )
{
if ( V_2 -> V_9 + V_15 > 65535 )
return 0 ;
if ( F_16 ( V_2 , 0 , V_15 - F_17 ( V_2 ) , V_16 ) )
return 0 ;
return 1 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_10 * V_17 ,
enum V_18 V_19 ,
unsigned int V_20 ,
unsigned int V_4 ,
unsigned int V_5 ,
const char * V_6 ,
unsigned int V_7 , bool V_21 )
{
const struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 , V_27 ;
if ( ! F_19 ( V_2 , V_2 -> V_9 ) )
return 0 ;
if ( V_7 > V_5 &&
V_7 - V_5 > F_17 ( V_2 ) &&
! F_15 ( V_2 , V_7 - V_5 ) )
return 0 ;
F_20 ( V_2 ) ;
V_25 = ( void * ) V_2 -> V_8 + V_20 ;
V_26 = V_2 -> V_9 - V_20 ;
F_1 ( V_2 , V_20 + V_25 -> V_28 * 4 ,
V_4 , V_5 , V_6 , V_7 ) ;
V_27 = V_2 -> V_9 - V_20 ;
V_23 = F_21 ( F_9 ( V_17 ) ) ;
V_23 -> V_29 ( V_2 , V_30 , V_25 , & V_25 -> V_31 ,
V_27 , V_26 ) ;
if ( V_21 && V_7 != V_5 )
F_22 ( V_17 , V_19 , V_25 -> V_32 ,
( int ) V_7 - ( int ) V_5 ) ;
return 1 ;
}
int
F_23 ( struct V_1 * V_2 ,
struct V_10 * V_17 ,
enum V_18 V_19 ,
unsigned int V_20 ,
unsigned int V_4 ,
unsigned int V_5 ,
const char * V_6 ,
unsigned int V_7 )
{
const struct V_22 * V_23 ;
struct V_33 * V_34 ;
int V_27 , V_26 ;
if ( ! F_19 ( V_2 , V_2 -> V_9 ) )
return 0 ;
if ( V_7 > V_5 &&
V_7 - V_5 > F_17 ( V_2 ) &&
! F_15 ( V_2 , V_7 - V_5 ) )
return 0 ;
V_34 = ( void * ) V_2 -> V_8 + V_20 ;
V_26 = V_2 -> V_9 - V_20 ;
F_1 ( V_2 , V_20 + sizeof( * V_34 ) ,
V_4 , V_5 , V_6 , V_7 ) ;
V_27 = V_2 -> V_9 - V_20 ;
V_34 -> V_9 = F_12 ( V_27 ) ;
if ( ! V_34 -> V_31 && V_2 -> V_35 != V_36 )
return 1 ;
V_23 = F_21 ( F_9 ( V_17 ) ) ;
V_23 -> V_29 ( V_2 , V_37 , V_34 , & V_34 -> V_31 ,
V_27 , V_26 ) ;
return 1 ;
}
void F_24 ( struct V_10 * V_17 ,
struct V_38 * exp )
{
struct V_39 V_40 ;
F_2 ( V_17 -> V_41 & V_42 ) ;
V_40 . V_43 = V_44 ;
V_40 . V_45 = V_40 . V_46
= V_17 -> V_47 -> V_48 [ ! exp -> V_49 ] . V_50 . V_51 . V_52 ;
F_25 ( V_17 , & V_40 , V_53 ) ;
V_40 . V_43 = ( V_44 | V_54 ) ;
V_40 . V_55 = V_40 . V_56 = exp -> V_57 ;
V_40 . V_45 = V_40 . V_46
= V_17 -> V_47 -> V_48 [ ! exp -> V_49 ] . V_50 . V_58 . V_52 ;
F_25 ( V_17 , & V_40 , V_59 ) ;
}
