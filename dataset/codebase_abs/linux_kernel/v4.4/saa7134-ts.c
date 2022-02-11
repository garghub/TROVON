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
struct V_17 * V_18 = F_11 ( V_16 ) ;
struct V_19 * V_20 = V_16 -> V_21 -> V_22 ;
struct V_3 * V_4 = F_12 ( V_18 , struct V_3 , V_16 ) ;
V_20 -> V_23 = NULL ;
V_4 -> V_24 = F_1 ;
return 0 ;
}
int F_13 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_11 ( V_16 ) ;
struct V_19 * V_20 = V_16 -> V_21 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = F_12 ( V_18 , struct V_3 , V_16 ) ;
struct V_25 * V_26 = F_14 ( V_16 , 0 ) ;
unsigned int V_27 , V_28 , V_29 ;
F_2 ( L_4 , V_4 ) ;
V_28 = V_30 ;
V_27 = V_2 -> V_31 . V_32 ;
V_29 = V_27 * V_28 ;
if ( F_15 ( V_16 , 0 ) < V_29 )
return - V_33 ;
F_16 ( V_16 , 0 , V_29 ) ;
V_18 -> V_34 = V_2 -> V_34 ;
return F_17 ( V_2 -> V_35 , & V_20 -> V_36 , V_26 -> V_37 , V_26 -> V_38 ,
F_18 ( V_4 ) ) ;
}
int F_19 ( struct V_21 * V_39 , const void * V_40 ,
unsigned int * V_41 , unsigned int * V_42 ,
unsigned int V_43 [] , void * V_44 [] )
{
struct V_19 * V_20 = V_39 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_2 ;
int V_29 = V_30 * V_2 -> V_31 . V_32 ;
if ( 0 == * V_41 )
* V_41 = V_2 -> V_31 . V_45 ;
* V_41 = F_20 ( V_29 , * V_41 ) ;
if ( * V_41 < 3 )
* V_41 = 3 ;
* V_42 = 1 ;
V_43 [ 0 ] = V_29 ;
V_44 [ 0 ] = V_2 -> V_46 ;
return 0 ;
}
int F_21 ( struct V_21 * V_47 , unsigned int V_48 )
{
struct V_19 * V_20 = V_47 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_2 ;
if ( F_22 ( & V_2 -> V_49 ) && V_2 -> V_50 -> V_51 ) {
struct V_3 * V_4 , * V_52 ;
F_23 (buf, tmp, &dmaq->queue, entry) {
F_24 ( & V_4 -> V_53 ) ;
F_25 ( & V_4 -> V_16 . V_54 ,
V_55 ) ;
}
if ( V_20 -> V_23 ) {
F_25 ( & V_20 -> V_23 -> V_16 . V_54 ,
V_55 ) ;
V_20 -> V_23 = NULL ;
}
return - V_56 ;
}
V_20 -> V_57 = 0 ;
return 0 ;
}
void F_26 ( struct V_21 * V_47 )
{
struct V_19 * V_20 = V_47 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_2 ;
F_27 ( V_2 ) ;
F_28 ( V_2 , V_20 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
F_30 ( V_58 , 0x00 ) ;
F_30 ( V_59 , 0x6c ) ;
F_30 ( V_60 , ( V_30 - 1 ) ) ;
F_30 ( V_61 , ( ( V_2 -> V_31 . V_32 - 1 ) & 0xff ) ) ;
F_30 ( V_62 , ( ( ( V_2 -> V_31 . V_32 - 1 ) >> 8 ) & 0xff ) ) ;
F_30 ( V_63 ,
( ( ( ( V_2 -> V_31 . V_32 - 1 ) >> 16 ) & 0x3f ) | 0x00 ) ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
if ( V_64 < 2 )
V_64 = 2 ;
if ( V_64 > V_65 )
V_64 = V_65 ;
if ( V_66 < 4 )
V_66 = 4 ;
if ( V_66 > 312 )
V_66 = 312 ;
V_2 -> V_31 . V_45 = V_64 ;
V_2 -> V_31 . V_32 = V_66 ;
F_32 ( & V_2 -> V_11 . V_67 ) ;
F_33 ( & V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_12 . V_68 = V_69 ;
V_2 -> V_11 . V_12 . V_70 = ( unsigned long ) ( & V_2 -> V_11 ) ;
V_2 -> V_11 . V_2 = V_2 ;
V_2 -> V_11 . V_71 = 1 ;
V_2 -> V_7 = 0 ;
F_34 ( V_2 -> V_35 , & V_2 -> V_11 . V_36 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( ! V_2 -> V_7 )
return 0 ;
switch ( V_72 [ V_2 -> V_73 ] . V_74 ) {
case V_75 :
F_30 ( V_59 , 0x6c ) ;
V_2 -> V_7 = 0 ;
break;
case V_76 :
F_30 ( V_77 , 0x40 ) ;
V_2 -> V_7 = 0 ;
break;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
F_2 ( L_6 ) ;
if ( F_35 ( V_2 -> V_7 ) )
return 0 ;
F_30 ( V_61 , ( V_2 -> V_31 . V_32 - 1 ) & 0xff ) ;
F_30 ( V_62 ,
( ( V_2 -> V_31 . V_32 - 1 ) >> 8 ) & 0xff ) ;
F_30 ( V_63 ,
( ( ( V_2 -> V_31 . V_32 - 1 ) >> 16 ) & 0x3f ) | 0x00 ) ;
F_3 ( F_36 ( 5 ) , V_30 ) ;
F_3 ( F_37 ( 5 ) , V_78 |
V_79 |
( V_2 -> V_11 . V_36 . V_26 >> 12 ) ) ;
F_30 ( V_58 , 0x00 ) ;
F_30 ( V_58 , 0x03 ) ;
F_30 ( V_58 , 0x00 ) ;
F_30 ( V_58 , 0x01 ) ;
F_30 ( V_58 , 0x00 ) ;
switch ( V_72 [ V_2 -> V_73 ] . V_74 ) {
case V_75 :
F_30 ( V_77 , 0x40 ) ;
F_30 ( V_59 , 0xec |
( V_72 [ V_2 -> V_73 ] . V_80 << 4 ) ) ;
break;
case V_76 :
F_30 ( V_77 , 0xd8 ) ;
F_30 ( V_59 , 0x6c |
( V_72 [ V_2 -> V_73 ] . V_80 << 4 ) ) ;
F_30 ( V_60 , 0xbc ) ;
F_30 ( V_58 , 0x02 ) ;
break;
}
V_2 -> V_7 = 1 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_35 , & V_2 -> V_11 . V_36 ) ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 , unsigned long V_81 )
{
enum V_82 V_34 ;
F_41 ( & V_2 -> V_83 ) ;
if ( V_2 -> V_11 . V_23 ) {
V_34 = V_2 -> V_8 ;
if ( V_34 != V_9 ) {
if ( ( V_81 & 0x100000 ) != 0x000000 )
goto V_84;
} else {
if ( ( V_81 & 0x100000 ) != 0x100000 )
goto V_84;
}
F_42 ( V_2 , & V_2 -> V_11 , V_85 ) ;
}
F_43 ( V_2 , & V_2 -> V_11 ) ;
V_84:
F_44 ( & V_2 -> V_83 ) ;
}
