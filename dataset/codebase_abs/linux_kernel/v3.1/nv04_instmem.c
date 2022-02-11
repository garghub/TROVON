static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 >= 0x40 )
return 128 ;
else
if ( V_4 -> V_6 >= 0x17 )
return 64 ;
return 32 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
T_1 V_9 , V_10 ;
int V_11 ;
V_4 -> V_12 = true ;
if ( V_4 -> V_13 >= V_14 ) {
T_1 V_15 = F_3 ( ( F_4 ( V_2 , 0x001540 ) & 0x0000ff00 ) >> 8 ) ;
T_1 V_16 ;
if ( V_4 -> V_6 == 0x40 ) V_16 = 0x6aa0 * V_15 ;
else if ( V_4 -> V_6 < 0x43 ) V_16 = 0x4f00 * V_15 ;
else if ( F_5 ( V_2 ) ) V_16 = 0x4980 * V_15 ;
else V_16 = 0x4a40 * V_15 ;
V_16 += 16 * 1024 ;
V_16 *= V_4 -> V_17 . V_18 . V_19 ;
if ( F_6 ( V_2 -> V_20 ) )
V_16 += 512 * 1024 ;
V_16 += 512 * 1024 ;
V_4 -> V_21 = F_7 ( V_16 , 4096 ) ;
} else {
V_4 -> V_21 = 512 * 1024 ;
}
V_11 = F_8 ( V_2 , 0x10000 , ~ 0 , 4096 ,
V_22 , & V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_9 ( V_2 , V_8 , & V_4 -> V_8 ) ;
F_10 ( NULL , & V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x11200 , ~ 0 , 512 ,
V_22 , & V_4 -> V_23 ) ;
if ( V_11 )
return V_11 ;
V_10 = V_4 -> V_17 . V_18 . V_19 * F_1 ( V_2 ) ;
switch ( V_4 -> V_13 ) {
case V_14 :
V_9 = 0x20000 ;
break;
default:
V_9 = 0x11400 ;
break;
}
V_11 = F_8 ( V_2 , V_9 , ~ 0 , V_10 ,
V_22 , & V_4 -> V_24 ) ;
if ( V_11 )
return V_11 ;
V_9 += V_10 ;
if ( V_4 -> V_13 >= V_14 ) {
if ( V_9 < 0x40000 )
V_9 = 0x40000 ;
}
V_11 = F_11 ( & V_4 -> V_25 , V_9 ,
V_4 -> V_21 - V_9 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_1 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
void
F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_14 ( NULL , & V_4 -> V_8 , NULL ) ;
F_10 ( NULL , & V_4 -> V_23 ) ;
F_10 ( NULL , & V_4 -> V_24 ) ;
if ( F_15 ( & V_4 -> V_25 ) )
F_16 ( & V_4 -> V_25 ) ;
}
int
F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
void
F_18 ( struct V_1 * V_2 )
{
}
int
F_19 ( struct V_7 * V_26 , struct V_27 * V_28 ,
T_1 V_29 , T_1 V_30 )
{
struct V_3 * V_4 = V_26 -> V_2 -> V_5 ;
struct V_31 * V_32 = NULL ;
do {
if ( F_20 ( & V_4 -> V_25 ) )
return - V_33 ;
F_21 ( & V_4 -> V_34 ) ;
V_32 = F_22 ( & V_4 -> V_25 , V_29 , V_30 , 0 ) ;
if ( V_32 == NULL ) {
F_23 ( & V_4 -> V_34 ) ;
return - V_33 ;
}
V_32 = F_24 ( V_32 , V_29 , V_30 ) ;
F_23 ( & V_4 -> V_34 ) ;
} while ( V_32 == NULL );
V_26 -> V_35 = V_32 ;
V_26 -> V_36 = V_32 -> V_37 ;
return 0 ;
}
void
F_25 ( struct V_7 * V_26 )
{
struct V_3 * V_4 = V_26 -> V_2 -> V_5 ;
F_21 ( & V_4 -> V_34 ) ;
F_26 ( V_26 -> V_35 ) ;
V_26 -> V_35 = NULL ;
F_23 ( & V_4 -> V_34 ) ;
}
int
F_27 ( struct V_7 * V_26 )
{
V_26 -> V_38 = V_26 -> V_36 ;
return 0 ;
}
void
F_28 ( struct V_7 * V_26 )
{
}
void
F_29 ( struct V_1 * V_2 )
{
}
