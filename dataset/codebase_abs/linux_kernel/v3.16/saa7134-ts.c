static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
F_2 ( L_1 , V_4 ) ;
V_4 -> V_6 = 0 ;
if ( ! V_2 -> V_7 )
V_2 -> V_8 = V_9 ;
if ( NULL == V_5 )
V_5 = V_4 ;
if ( V_9 == V_2 -> V_8 ) {
F_2 ( L_2 , V_4 , V_5 ) ;
F_3 ( F_4 ( 5 ) , F_5 ( V_4 ) ) ;
F_3 ( F_6 ( 5 ) , F_5 ( V_5 ) ) ;
V_2 -> V_8 = V_10 ;
} else {
F_2 ( L_3 , V_4 , V_5 ) ;
F_3 ( F_4 ( 5 ) , F_5 ( V_5 ) ) ;
F_3 ( F_6 ( 5 ) , F_5 ( V_4 ) ) ;
V_2 -> V_8 = V_9 ;
}
F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_11 . V_12 , V_13 + V_14 ) ;
if ( ! V_2 -> V_7 )
F_9 ( V_2 ) ;
return 0 ;
}
int F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 -> V_20 ;
struct V_3 * V_4 = F_11 ( V_16 , struct V_3 , V_16 ) ;
V_18 -> V_21 = NULL ;
V_4 -> V_22 = F_1 ;
return 0 ;
}
int F_12 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = F_11 ( V_16 , struct V_3 , V_16 ) ;
struct V_23 * V_24 = F_13 ( V_16 , 0 ) ;
unsigned int V_25 , V_26 , V_27 ;
int V_28 ;
F_2 ( L_4 , V_4 ) ;
V_26 = V_29 ;
V_25 = V_2 -> V_30 . V_31 ;
V_27 = V_25 * V_26 ;
if ( F_14 ( V_16 , 0 ) < V_27 )
return - V_32 ;
F_15 ( V_16 , 0 , V_27 ) ;
V_16 -> V_33 . V_34 = V_2 -> V_34 ;
V_28 = F_16 ( & V_2 -> V_35 -> V_2 , V_24 -> V_36 , V_24 -> V_37 , V_38 ) ;
if ( ! V_28 )
return - V_39 ;
return F_17 ( V_2 -> V_35 , & V_18 -> V_40 , V_24 -> V_36 , V_24 -> V_37 ,
F_18 ( V_4 ) ) ;
}
void F_19 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = F_11 ( V_16 , struct V_3 , V_16 ) ;
struct V_23 * V_24 = F_13 ( & V_4 -> V_16 , 0 ) ;
F_20 ( & V_2 -> V_35 -> V_2 , V_24 -> V_36 , V_24 -> V_37 , V_38 ) ;
}
int F_21 ( struct V_19 * V_41 , const struct V_42 * V_43 ,
unsigned int * V_44 , unsigned int * V_45 ,
unsigned int V_46 [] , void * V_47 [] )
{
struct V_17 * V_18 = V_41 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_27 = V_29 * V_2 -> V_30 . V_31 ;
if ( 0 == * V_44 )
* V_44 = V_2 -> V_30 . V_48 ;
* V_44 = F_22 ( V_27 , * V_44 ) ;
if ( * V_44 < 3 )
* V_44 = 3 ;
* V_45 = 1 ;
V_46 [ 0 ] = V_27 ;
return 0 ;
}
int F_23 ( struct V_19 * V_49 , unsigned int V_50 )
{
struct V_17 * V_18 = V_49 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( F_24 ( & V_2 -> V_51 ) && V_2 -> V_43 -> V_52 ) {
struct V_3 * V_4 , * V_53 ;
F_25 (buf, tmp, &dmaq->queue, entry) {
F_26 ( & V_4 -> V_54 ) ;
F_27 ( & V_4 -> V_16 , V_55 ) ;
}
if ( V_18 -> V_21 ) {
F_27 ( & V_18 -> V_21 -> V_16 , V_55 ) ;
V_18 -> V_21 = NULL ;
}
return - V_56 ;
}
V_18 -> V_57 = 0 ;
return 0 ;
}
void F_28 ( struct V_19 * V_49 )
{
struct V_17 * V_18 = V_49 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_29 ( V_2 ) ;
F_30 ( V_2 , V_18 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
F_32 ( V_58 , 0x00 ) ;
F_32 ( V_59 , 0x6c ) ;
F_32 ( V_60 , ( V_29 - 1 ) ) ;
F_32 ( V_61 , ( ( V_2 -> V_30 . V_31 - 1 ) & 0xff ) ) ;
F_32 ( V_62 , ( ( ( V_2 -> V_30 . V_31 - 1 ) >> 8 ) & 0xff ) ) ;
F_32 ( V_63 ,
( ( ( ( V_2 -> V_30 . V_31 - 1 ) >> 16 ) & 0x3f ) | 0x00 ) ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
if ( V_64 < 2 )
V_64 = 2 ;
if ( V_64 > V_65 )
V_64 = V_65 ;
if ( V_66 < 4 )
V_66 = 4 ;
if ( V_66 > 312 )
V_66 = 312 ;
V_2 -> V_30 . V_48 = V_64 ;
V_2 -> V_30 . V_31 = V_66 ;
F_34 ( & V_2 -> V_11 . V_67 ) ;
F_35 ( & V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_12 . V_68 = V_69 ;
V_2 -> V_11 . V_12 . V_70 = ( unsigned long ) ( & V_2 -> V_11 ) ;
V_2 -> V_11 . V_2 = V_2 ;
V_2 -> V_11 . V_71 = 1 ;
V_2 -> V_7 = 0 ;
F_36 ( V_2 -> V_35 , & V_2 -> V_11 . V_40 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( ! V_2 -> V_7 )
return 0 ;
switch ( V_72 [ V_2 -> V_73 ] . V_74 ) {
case V_75 :
F_32 ( V_59 , 0x6c ) ;
V_2 -> V_7 = 0 ;
break;
case V_76 :
F_32 ( V_77 , 0x40 ) ;
V_2 -> V_7 = 0 ;
break;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
F_2 ( L_6 ) ;
if ( F_37 ( V_2 -> V_7 ) )
return 0 ;
F_32 ( V_61 , ( V_2 -> V_30 . V_31 - 1 ) & 0xff ) ;
F_32 ( V_62 ,
( ( V_2 -> V_30 . V_31 - 1 ) >> 8 ) & 0xff ) ;
F_32 ( V_63 ,
( ( ( V_2 -> V_30 . V_31 - 1 ) >> 16 ) & 0x3f ) | 0x00 ) ;
F_3 ( F_38 ( 5 ) , V_29 ) ;
F_3 ( F_39 ( 5 ) , V_78 |
V_79 |
( V_2 -> V_11 . V_40 . V_24 >> 12 ) ) ;
F_32 ( V_58 , 0x00 ) ;
F_32 ( V_58 , 0x03 ) ;
F_32 ( V_58 , 0x00 ) ;
F_32 ( V_58 , 0x01 ) ;
F_32 ( V_58 , 0x00 ) ;
switch ( V_72 [ V_2 -> V_73 ] . V_74 ) {
case V_75 :
F_32 ( V_77 , 0x40 ) ;
F_32 ( V_59 , 0xec |
( V_72 [ V_2 -> V_73 ] . V_80 << 4 ) ) ;
break;
case V_76 :
F_32 ( V_77 , 0xd8 ) ;
F_32 ( V_59 , 0x6c |
( V_72 [ V_2 -> V_73 ] . V_80 << 4 ) ) ;
F_32 ( V_60 , 0xbc ) ;
F_32 ( V_58 , 0x02 ) ;
break;
}
V_2 -> V_7 = 1 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 -> V_35 , & V_2 -> V_11 . V_40 ) ;
return 0 ;
}
void F_42 ( struct V_1 * V_2 , unsigned long V_81 )
{
enum V_82 V_34 ;
F_43 ( & V_2 -> V_83 ) ;
if ( V_2 -> V_11 . V_21 ) {
V_34 = V_2 -> V_8 ;
if ( V_34 != V_9 ) {
if ( ( V_81 & 0x100000 ) != 0x000000 )
goto V_84;
} else {
if ( ( V_81 & 0x100000 ) != 0x100000 )
goto V_84;
}
F_44 ( V_2 , & V_2 -> V_11 , V_85 ) ;
}
F_45 ( V_2 , & V_2 -> V_11 ) ;
V_84:
F_46 ( & V_2 -> V_83 ) ;
}
