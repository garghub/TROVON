long F_1 ( struct V_1 * V_2 , int V_3 , unsigned long T_1 * V_4 )
{
unsigned long * V_5 = V_4 , V_6 ;
long V_7 ;
int V_8 = V_2 -> V_9 -> V_10 . V_11 . V_12 . V_8 ;
switch ( V_3 ) {
case V_13 :
case V_14 :
V_7 = F_2 ( V_8 , & V_15 -> V_16 . V_17 . V_17 ) ;
if ( V_7 )
return V_7 ;
break;
case V_18 :
case V_19 :
V_5 = & V_6 ;
}
V_7 = F_3 ( V_8 , V_3 , V_5 ) ;
if ( V_7 )
return V_7 ;
switch ( V_3 ) {
case V_13 :
V_15 -> V_16 . V_20 . V_21 = ( unsigned long ) V_5 ;
V_7 = F_4 ( V_8 , & V_15 -> V_16 . V_17 . V_17 ) ;
break;
case V_14 :
V_7 = F_4 ( V_8 , & V_15 -> V_16 . V_17 . V_17 ) ;
break;
case V_18 :
V_7 = F_5 ( V_6 , V_4 ) ;
break;
case V_19 :
V_7 = F_5 ( V_6 , V_4 ) ;
break;
}
return V_7 ;
}
long F_6 ( int V_3 , unsigned long V_4 )
{
return F_1 ( V_15 , V_3 , ( unsigned long T_1 * ) V_4 ) ;
}
void F_7 ( struct V_1 * V_22 )
{
if ( ( V_22 -> V_16 . V_20 . V_21 == 0 ) || ( V_22 -> V_9 == NULL ) )
return;
F_1 ( V_22 , V_13 , ( void T_1 * ) V_22 -> V_16 . V_20 . V_21 ) ;
}
